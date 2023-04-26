#include <stdio.h>
#include <stdlib.h>

int Summation(int Arr[], int iSize)
{
	int iSum = 0, iCnt = 0;
	for(iCnt = 0; iCnt < iSize; iCnt++)
	{
		iSum = iSum + Arr[iCnt];
	}
	return (iSum);
}

int main()
{
	int iLength = 0, *ptr = NULL, iCnt = 0, iRet = 0;

	printf("Enter no of elements \n");
	scanf("%d", &iLength);

	ptr = (int *) malloc(sizeof(int) * iLength);

	for(iCnt = 0; iCnt < iLength; iCnt++)
	{
		printf("Enter value of element %d : \n", iCnt+1);
		scanf("%d", &ptr[iCnt]);
	}

	iRet = Summation(ptr, iLength);

	printf("Addition is : %d \n", iRet);

	free(ptr);
	ptr = NULL;

	return (0);
}
