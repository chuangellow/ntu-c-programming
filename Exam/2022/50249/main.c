#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define STR_LEN 101

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
	char A_name[STR_LEN] = {'\0'}, out_name[STR_LEN] = {'\0'};
	int k;
	scanf("%s%s%d", A_name, out_name, &k);
	FILE* file_A_fp = read_input(A_name, "rb");
	FILE* file_out_fp = read_input(out_name, "wb");

	WAVHeader header_A, header_out;
	fread(&header_A, sizeof(WAVHeader), 1, file_A_fp);
	fseek(file_A_fp, 0, SEEK_SET);
	fread(&header_out, sizeof(WAVHeader), 1, file_A_fp);
	fwrite(&header_out, sizeof(WAVHeader), 1, file_out_fp);
	int bytes_per_sec = header_A.sampleRate * header_A.bitsPerSample * header_A.numChannel / 8;
	int bytes_to_switch = bytes_per_sec * k;
	bytes_to_switch = (bytes_to_switch < header_A.dataSize)? bytes_to_switch: header_A.dataSize;
	char *out_buffer = malloc(header_A.dataSize * sizeof(char));
	fread(out_buffer, bytes_to_switch, 1, file_A_fp);
	for (int i = 0; i <  bytes_to_switch; i+=4) {
		char temp = out_buffer[i+0], temp2 = out_buffer[i+1];
		out_buffer[i+0] = out_buffer[i+2];
		out_buffer[i+1] = out_buffer[i+3];
		out_buffer[i+2] = temp;
		out_buffer[i+3] = temp2;
	}
	fwrite(out_buffer, bytes_to_switch, 1, file_out_fp);
	fread(out_buffer, header_A.dataSize - bytes_to_switch, 1, file_A_fp);
	fwrite(out_buffer, header_A.dataSize - bytes_to_switch, 1, file_out_fp);
	fclose(file_A_fp);
	fclose(file_out_fp);
	return 0;
}
