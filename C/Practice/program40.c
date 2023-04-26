#include <stdio.h>
#include <stdbool.h>

int CountFactor(int iNo)
{
	int iCnt = 0;
	int iCntFactor = 0;

	for(iCnt = 1; iCnt <= (iNo/2); iCnt++)
	{
		if((iNo % iCnt) == 0)
		{
			iCntFactor++;
		}
	}
	return iCntFactor;
}

int main()
{
	int iValue = 0;
	int iRet = 0;

	printf("Enter nuo. : \n");
	scanf("%d", &iValue);

	iRet = CountFactor(iValue);

	printf("No. of factors are : %d \n", iRet);
	
	return (0);
}
