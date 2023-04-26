#include <stdio.h>

#define TRUE 1
#define FALSE 0
typedef int BOOL;

BOOL CheckArmstrong(int iNo)
{
	int iCnt = 0;
	int iDigit = 0;
	int iDigitCnt = 0;
	int iSum = 0;
	int iMult = 1;

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
		iMult = 1;
		iDigit = iNo % 10;
		
		for(iCnt = 1; iCnt <= iDigitCnt; iCnt++)
		{
			iMult = iMult * iDigit;
		}

		iSum = iSum + iMult;
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
