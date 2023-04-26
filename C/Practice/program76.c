// Find occurrence

// Time Complexity - 'N'

#include <stdio.h>
#include <stdlib.h>

int CheckFrequency(int Arr[], int iLength, int iNo)
{
	int iCnt = 0;
	int iFreq = 0;

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		if(iNo == Arr[iCnt])
		{
			iFreq++;
		}
	}
	return (iFreq);
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

	iRet = CheckFrequency(ptr, iSize, iValue);
	printf("%d has frequency : %d.\n", iValue, iRet);

	free(ptr);

	ptr = NULL;

	return (0);
}
