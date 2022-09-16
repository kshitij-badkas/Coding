#include <stdio.h>

int SumFactors(int iNo)
{
	auto int iCnt = 0;
	auto int iSum = 0;

	// Updater
	if(iNo < 0)
	{
		iNo = -iNo;
	}

	for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
	{
		if((iNo % iCnt) == 0)
		{
			iSum = iSum + iCnt;
		}
	}
	return (iSum);
}

int main()
{	
	auto int iValue = 0;
	auto int iRet = 0;

	printf("Enter no. : \n");
	scanf("%d", &iValue);

	iRet = SumFactors(iValue);
	printf("%d\n", iRet);

	return (0);
}


// Time Complexity : O(N/2) -> Big O Notation (Order of)
