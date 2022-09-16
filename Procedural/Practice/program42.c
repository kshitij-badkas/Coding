#include <stdio.h>
#include <stdbool.h>

int CountFactor(int iNo)
{
	int iCnt = 0;
	int iCntFactor = 0;

	if(iNo < 0)
	{
		iNo = -iNo;
	}

	for(iCnt = 2; iCnt <= (iNo/2); iCnt++)
	{
		if((iNo % iCnt) == 0)
		{
			iCntFactor++;
		}
	}
	return (iCntFactor);
}

bool CheckPrime(int iNo)
{
	int iRet = 0;
	iRet = CountFactor(iNo);

	if(iRet == 0)
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
	int iValue = 0;
	bool bRet = false;

	printf("Enter nuo. : \n");
	scanf("%d", &iValue);

	bRet = CheckPrime(iValue);
	if(bRet == true)
	{
		printf("%d is a prime no.\n",iValue);
	}
	else
	{
		printf("%d is NOT a prime no.\n",iValue);
	}

	return (0);
}
