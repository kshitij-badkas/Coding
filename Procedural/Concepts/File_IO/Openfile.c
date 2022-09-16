#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	char fname[30];
	int fd = 0;

	printf("Enter the file name to open : \n");
	scanf("%s", fname);

	fd = open(fname, O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file.\n");	
	}
	else
	{
		printf("File is successfully opened with fd : %d.\n", fd);
	}

	return (0);
}
