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

	// 1. File descriptor - Kashat
	// 2. Displavcement - Kitine halchal
	// 3. From where - Kuthun (0 - start of file, 1 - current position, 2 - end of file)
	
	// lseek(fd, 4, 0);
	lseek(fd, -7, 2);

	read(fd, Data, 6);

	write(1, Data, 6);

	close(fd);

	return (0);
}
