#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>	// file control

int main()
{
	char fname[30];
	int fd = 0; 	// fileDescriptor

	printf("Enter the file name to be created : \n");
	scanf("%s", fname);

	fd = creat(fname, 0777);
	if(fd == -1)
	{
		printf("Unable to create file.\n");	
	}
	else
	{
		printf("File is successfully created with fd : %d.\n", fd);
	}

	return (0);
}
