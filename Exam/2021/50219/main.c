#include <stdio.h>
#include <assert.h>

#define STR_LEN 100

typedef struct WAVheader
{
  char RIFF[4];
  int chunkSize;
  char wave[4];
  char format[4];
  int subChunkSize;
  short audioFormat;
  short numChannel;
  int sampleRate;
  int byteRate;
  short blockAlign;
  short bitsPerSample;
  char data[4];
  int dataSize;
} WAVHeader;

FILE* read_input(char name[STR_LEN], const char* mode) {
	FILE *file_fp;
	file_fp = fopen(name, mode);
	assert(file_fp != NULL);
	return file_fp;
}

int main(void) {
	char A_name[STR_LEN] = {'\0'}, B_name[STR_LEN] = {'\0'}, out_name[STR_LEN] = {'\0'};
	scanf("%s%s%s", A_name, B_name, out_name);
	FILE* file_A_fp = read_input(A_name, "rb");
	FILE* file_B_fp = read_input(B_name, "rb");
	FILE* file_out_fp = read_input(out_name, "wb");

	WAVHeader header_A, header_B, header_out;
	fread(&header_A, sizeof(WAVHeader), 1, file_A_fp);
	fread(&header_B, sizeof(WAVHeader), 1, file_B_fp);

	fseek(file_A_fp, 0, SEEK_SET);
	fread(&header_out, sizeof(WAVHeader), 1, file_A_fp);
	int chunkSize_A = header_A.dataSize + 36;
	int chunkSize_B = header_B.dataSize + 36;
	header_out.chunkSize = chunkSize_A + chunkSize_B - 36;
	header_out.dataSize = header_A.dataSize + header_B.dataSize;
	fwrite(&header_out, sizeof(WAVHeader), 1, file_out_fp);
	char out_buffer[4000000];
	fread(out_buffer, header_A.dataSize, 1, file_A_fp);
	fwrite(out_buffer, header_A.dataSize, 1, file_out_fp);
	fread(out_buffer, header_B.dataSize, 1, file_B_fp);
	fwrite(out_buffer, header_B.dataSize, 1, file_out_fp);
	fclose(file_A_fp);
	fclose(file_B_fp);
	fclose(file_out_fp);
	return 0;
}
