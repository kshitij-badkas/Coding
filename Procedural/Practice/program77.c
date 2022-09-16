// Check if no. is in Array or not.

// Time Complexity - Best case 1
// Time Complexity - Avg case N/2
// Time Complexity - Worst case N

#include <stdio.h>
#include <stdlib.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

BOOL Search(int Arr[], int iLength, int iNo)
{
	int iCnt = 0;
	BOOL bFlag = FALSE;

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(iNo == Arr[iCnt])
		{
			bFlag = TRUE;
			break;	
		}
	}
	return (bFlag);
}

int main()
{
	int iSize = 0;
	int *ptr = NULL;
	int iCnt = 0;
	BOOL bRet = FALSE;
	int iValue = 0;

	printf("Enter no. of elements : \n");
	scanf("%d", &iSize);

	ptr = (int*) malloc(iSize * sizeof(int));

	printf("Enter the values : \n");
	for(iCnt = 0; iCnt < iSize; iCnt++)
	{
		scanf("%d", &ptr[iCnt]);
	}

	printf("Enter the no. to search : \n");
	scanf("%d", &iValue);

	bRet = Search(ptr, iSize, iValue);
	if(bRet == TRUE)
	{
		printf("%d is present. \n", iValue);
	}
	else
	{
		printf("%d is NOT present. \n", iValue);
	}

	free(ptr);

	ptr = NULL;

	return (0);
}
