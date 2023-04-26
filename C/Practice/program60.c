#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

int Power(int iNo1, int iNo2)
{
	register int iCnt = 0;
	auto int lMult = 1;

	for(iCnt = 1; iCnt <= iNo2; iCnt++)
	{
		lMult = lMult * iNo1;
	}
	return (lMult);
}

BOOL CheckArmstrong(int iNo)
{
	int iCnt = 0;
	int iDigit = 0;
	int iDigitCnt = 0;
	int iSum = 0;

	// Updater
	if(iNo < 0)
	{
		iNo = -iNo;
	}

	int iTemp = iNo;			// create copy of iNo

	// Count no. of Digits
	while(iNo != 0)
	{
		// iDigit = iNo % 10;
		iDigitCnt ++;
		iNo = iNo / 10;
	}

	// Calculate Power
	iNo = iTemp;				// Reset iNo
	while(iNo != 0)
	{
		iDigit = iNo % 10;
		iSum = iSum + Power(iDigit, iDigitCnt);
		iNo = iNo / 10;
	}

	if(iSum == iTemp)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}  

int main()
{
	auto int iValue = 0;
	BOOL bRet = FALSE;

	printf("Enter no : \n");
	scanf("%d", &iValue);

	bRet = CheckArmstrong(iValue);
	if(bRet == TRUE)
	{
		printf("%d is Armstrong \n", iValue);
	}
	else
	{
		printf("%d is NOT Armstrong \n", iValue);
	}
	
	return (0);
}
