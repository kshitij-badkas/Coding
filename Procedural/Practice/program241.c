#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	char Fname[20];
	char Data[10];
	int iRet = 0;

	int fd = 0;		// File Descriptor

	printf("Enter file name to open : \n");
	scanf("%s", Fname);

	fd = open(Fname, O_RDWR | O_APPEND);
	if(fd == -1)
	{
		printf("Unable to open the file.\n");
		return (-1);	// Failure
	}

	printf("File is successfully opened with FD %d\n", fd);

	iRet = read(fd, Data, 100);
	
	printf("%d Bytes get successfully read from the file.\n", iRet);

	write(1, Data, sizeof(Data));
	write(1, Data, sizeof(Data));
	write(1, Data, sizeof(Data));
 
	return (0);
}
