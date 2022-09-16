#include <stdio.h>
#include <stdlib.h>		// malloc() & free()

void Display(int Arr[], int iLength)
{
	register int iCnt = 0;

	printf("Elements of array : \n");

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		printf("%d\n", Arr[iCnt]);
	}
}

int main()
{
	auto int iSize = 0;
	auto int *iPtr = NULL;
	register int iCnt = 0;

	printf("Enter no. of elements wanted : \n");
	scanf("%d", &iSize);

	iPtr = (int*)malloc(sizeof(int) * iSize);
	if(iPtr == NULL)
	{
		printf("Memory allocation failed. \n");
	}
	else
	{
		printf("Eneter elements of size  : %d \n", iSize);
		for(iCnt = 0; iCnt < iSize; iCnt++)
		{
			printf("Eneter elements no. %d \n", iCnt);
			scanf("%d", &iPtr[iCnt]);
		}

		Display(iPtr, iSize);

		free(iPtr);
	
	}
		
	return (0);
}
