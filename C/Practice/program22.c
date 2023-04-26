// Summation of numbers

#include <stdio.h>

int Summation(int iNo)
{
	int iCnt = 0;
	int iSum = 0;
	
	// Updater
	if(iNo < 0)
	{
		iNo = -iNo;
	}
	
	for (iCnt = 1; iCnt <= iNo; iCnt++)
	{
		iSum = iSum + iCnt;
	}
	
	return (iSum);
	
}

int main()
{
	int iValue = 0;
	int iRet = 0;
	
	printf("Enter no. \n");
	scanf("%d", &iValue);
	printf("**********\n");
	
	iRet = Summation(iValue);
	printf("%d \n", iRet);
	
	return (0);
}
