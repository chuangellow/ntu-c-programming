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
	char input_name[STR_LEN];
	char output_name[STR_LEN];
	scanf("%s%s", input_name, output_name);
	int duration;
	scanf("%d", &(duration));

	FILE *infp, *outfp;
	infp = fopen(input_name, "rb");
	assert(infp != NULL);
	outfp = fopen(output_name, "wb");
	assert(outfp != NULL);

	WAVHeader in_header, out_header;
	fread(&(in_header), sizeof(WAVHeader), 1, infp);
	fseek(infp, 0, SEEK_SET);
	fread(&(out_header), sizeof(WAVHeader), 1, infp);
	
	int bytes_per_sec = in_header.sampleRate * in_header.bitsPerSample * in_header.numChannel / 8;
	int bytes_to_write = bytes_per_sec * duration;
	out_header.dataSize = bytes_to_write * in_header.numChannel;
	out_header.chunkSize = bytes_to_write + 36;

	fwrite(&(out_header), sizeof(WAVHeader), 1, outfp);
	char *out_buffer = malloc(in_header.dataSize * sizeof(char));
	fread(out_buffer, bytes_to_write, 1, infp);
	fwrite(out_buffer, bytes_to_write, 1, outfp);

	fclose(infp);
	fclose(outfp);

	return 0;
}
