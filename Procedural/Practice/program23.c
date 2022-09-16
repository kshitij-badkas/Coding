// Summation of numbers

#include <stdio.h>
#include <stdbool.h>

bool ChkEven(int iNo)
{
	if((iNo % 2) == 0)
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
	bool bRet = false;		// default value for bool
	
	printf("Enter no. \n");
	scanf("%d", &iValue);
	printf("**********\n");
	
	bRet = ChkEven(iValue);
	if(bRet == true)
	{
		printf("%d is even \n", iValue);
	}
	else
	{
		printf("%d is odd \n", iValue);
	}
	
	return (0);
}
