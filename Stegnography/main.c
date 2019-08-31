#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	switch(argc)
	{
		case 5 :	if(!strcmp(argv[1], "-e"))
				{
					encryption(argv[2], argv[3], argv[4]);
					break;
				}
		case 4 :	if(!strcmp(argv[1], "-d"))
				{
					dycryption(argv[2], argv[3]);
					break;
				}
		default : printf("Not enought argument passed\n");
	}	
}
