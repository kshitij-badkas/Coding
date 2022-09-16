#include <stdio.h>
#include <stdbool.h>

bool CheckPrime(int iNo)
{
	int iCnt = 0;
	bool bFlag = true;

	for(iCnt = 2; iCnt <= (iNo/2); iCnt++)
	{
		if(iNo % iCnt == 0)
		{
			bFlag = false;
			break;
		}
	}
	return (bFlag);
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
		printf("%d is Prime no. \n", iValue);
	}
	else
	{
		printf("%d is NOT a Prime no. \n", iValue);
	}

	return (0);
}
