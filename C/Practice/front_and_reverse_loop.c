#include <stdio.h>
#include <stdlib.h>

int SearchFirstOccurence(int Arr[], int iLength, int iNo)
{
	int iCntF = 0, iCntR = 0;

	for(iCntF = 0, iCntR = (iLength - 1); iCntF <= (iLength / 2), iCntR >= (iLength / 2); iCntF++, iCntR--)
	{
		if((iNo == Arr[iCntF]) || (iNo == Arr[iCntR]))
		{
			break;	
		}
	}
	if((iCntF == (iLength / 2)) && (iCntR == (iLength / 2)))
	{
		return (-1);
	}
	else
	{
		// ithe kay return karu ?
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
