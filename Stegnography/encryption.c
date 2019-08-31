uint get_image_size_for_bmp(FILE *fptr_image)
{
	uint width, height;
	// Seek to 18th byte
	fseek(fptr_image, 18, SEEK_SET);

	// Read the width (an int)
	fread(&width, sizeof(int), 1, fptr_image);


	// Read the height (an int)
	fread(&height, sizeof(int), 1, fptr_image);

	// Return image capacity
	return width * height * 3;
}
Status open_files(EncodeInfo *encInfo)
{
	// Src Image file
	encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
	// To check whether image file is there or not
	if (encInfo->fptr_src_image == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);

		return e_failure;
	}
	
	encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
	// To check whether secret file has text or not
	if (encInfo->fptr_secret == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);
		return e_failure;
	}
	encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
	if (encInfo->fptr_stego_image == NULL)
	{
		perror("fopen");
		fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);
		return e_failure;
	}
	return e_success;
}
OperationType check_operation_type(char *argv[])// to check arguments what we are giving -e or -d]
{
	if (!strcmp(argv[1], "-e"))
	{
		return e_encode;	// '0'
	}
	else
	{
		return e_unsupported;	// '2'
	}
}
