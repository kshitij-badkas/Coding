// Check the first occurence of a no. in an array and return the index, else return -1.

// Time Complexity - Best case 1
// Time Complexity - Avg case N/2
// Time Complexity - Worst case N

#include <stdio.h>
#include <stdlib.h>

int SearchFirstOccurence(int Arr[], int iLength, int iNo)
{
	int iCnt = 0;

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(iNo == Arr[iCnt])
		{
			break;	
		}
	}
	if(iCnt == iLength)
	{
		return (-1);
	}
	else
	{
		return (iCnt);
	}
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

	iRet = SearchFirstOccurence(ptr, iSize, iValue);
	if(iRet == -1)
	{
		printf("%d is NOT present. \n", iValue);
	}
	else
	{
		printf("The index of first occurence is %d \n", iRet);
	}

	free(ptr);

	ptr = NULL;

	return (0);
}
