#include <stdio.h>
#include <stdbool.h>

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

bool CheckPerfect(int iNo)
{
	int iAns = 0;
	iAns = SumFactors(iNo);
	
	if(iAns == iNo)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{	
	auto int iValue = 0;
	auto int iRet = 0;
	auto bool bRet = false;

	printf("Enter no. : \n");
	scanf("%d", &iValue);

	bRet = CheckPerfect(iValue);
	if(bRet == true)
	{
		printf("%d is a Perfect No. \n", iValue);
	}
	else
	{
		printf("%d is NOT a Perfect No. \n", iValue);
	}




	return (0);
}

// Time Complexity : O(N/2) -> Big O Notation (Order of)