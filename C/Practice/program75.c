// Smallest number from array

// Time Complexity - 'N'

#include <stdio.h>
#include <stdlib.h>

// Positive AND NEGATIVE numbers
int Minimum(int Arr[], int iLength)
{
	int iCnt = 0;
	int iMin = Arr[0];

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(iMin > Arr[iCnt])
		{
			iMin = Arr[iCnt];
		}
	}
	return (iMin);
}

int main()
{
	int iSize = 0;
	int *ptr = NULL;
	int iCnt = 0;
	int iRet = 0;

	printf("Enter no. of elements : \n");
	scanf("%d", &iSize);

	ptr = (int*) malloc(iSize * sizeof(int));

	printf("Enter the values : \n");
	for(iCnt = 0; iCnt < iSize; iCnt++)
	{
		scanf("%d", &ptr[iCnt]);
	}

	iRet = Minimum(ptr, iSize);
	printf("Minimum is  : %d\n", iRet);

	free(ptr);

	ptr = NULL;

	return (0);
}
