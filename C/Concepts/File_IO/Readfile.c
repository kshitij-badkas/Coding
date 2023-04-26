#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	char fname[30];
	int fd = 0;
	char Data[11];
	int ret = 0;

	printf("Enter the file name to open : \n");
	scanf("%s", fname);

	fd = open(fname, O_RDWR);
	if(fd == -1)
	{
		printf("Unable to open file.\n");
		return (-1);	
	}
	else
	{
		printf("File is successfully opened with fd : %d.\n", fd);
	}

	read(fd, Data, 6);

	// printf("Data from file is : %s\n", Data);
	write(1, Data, 6);

	close(fd);

	return (0);
}
