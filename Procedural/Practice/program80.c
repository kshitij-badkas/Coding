// Check the last occurence of a no. in an array and return the index

// Time Complexity - Best case 1
// Time Complexity - Avg case N/2
// Time Complexity - Worst case N

#include <stdio.h>
#include <stdlib.h>

int SearchLastOccurence(int Arr[], int iLength, int iNo)
{
	int iCnt = 0;

	for(iCnt = iLength - 1; iCnt >= 0; iCnt--)		// Reverse
	{
		if(iNo == Arr[iCnt])
		{
			break;	
		}
	}
	
	return (iCnt);		// iCnt becomes -1 if loop is executed fully
}

int main()
{
	int iSize = 0;
	int *ptr = NULL;
	int iCnt = 0;
	int iRet = 0;
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

	iRet = SearchLastOccurence(ptr, iSize, iValue);
	if(iRet == -1)
	{
		printf("%d is NOT present. \n", iValue);
	}
	else
	{
		printf("The index of last occurence is %d \n", iRet);
	}

	free(ptr);

	ptr = NULL;

	return (0);
}
