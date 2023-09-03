#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STR_LEN 1000

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

int main(void) {
	char A_name[STR_LEN] = "\0", B_name[STR_LEN] = "\0", out_name[STR_LEN] = "\0";
	scanf("%s%s%s", A_name, B_name, out_name);

	FILE *A_fp, *B_fp, *out_fp;
	A_fp = fopen(A_name, "rb");
	B_fp = fopen(B_name, "rb");
	out_fp = fopen(out_name, "wb");
	assert((A_fp != NULL) && (B_fp != NULL) && (out_fp != NULL));

	WAVHeader A_header, B_header;
	fread(&(A_header), sizeof(WAVHeader), 1, A_fp);
	fread(&(B_header), sizeof(WAVHeader), 1, B_fp);
	fwrite(&(A_header), sizeof(WAVHeader), 1, out_fp);

	short *A_buffer = (short *)malloc(A_header.dataSize);
	short *B_buffer = (short *)malloc(B_header.dataSize);
	short *out_buffer = (short *)malloc(A_header.dataSize);

	fread(A_buffer, sizeof(short), A_header.dataSize / 2, A_fp);
	fread(B_buffer, sizeof(short), B_header.dataSize / 2, B_fp);

	for (int i = 0; i <  A_header.dataSize / 2; i++) {
		out_buffer[i] = A_buffer[i] - B_buffer[i];
	}

	fwrite(out_buffer, sizeof(short), A_header.dataSize / 2, out_fp);

	free(A_buffer);
	free(B_buffer);
	fclose(A_fp);
	fclose(B_fp);
	fclose(out_fp);

	return 0;
}
