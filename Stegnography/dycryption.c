#include <stdio.h>

int read_size(FILE *f)
{
		int size;
		fseek(f, 0, SEEK_END); // seek to end of file
		size = ftell(f); // get current file pointer
		fseek(f, 0, SEEK_SET); // seek back to beginning of file
		// proceed with allocating memory and reading the file
}

void read_msg_from_stego_image(FILE *stego_file, FILE *txt_file, int msg_size)
{
}
void dycryption(char *stego_filename, char *txt_filename)
{
}
