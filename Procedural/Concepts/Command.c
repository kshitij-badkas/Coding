#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int iAns = 0;

	printf("Name of executable is : %s\n", argv[0]);
	printf("Number of arguments : %d\n", argc);
	printf("Jay Ganesh\n");

	iAns = atoi(argv[1]) + atoi(argv[2]);
	printf("Addition is : %d\n", iAns);

	return (0);
}
