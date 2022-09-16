// Summation of numbers

#include <stdio.h>
#include <stdbool.h>

bool Check(int iNo)
{
	if(
		((iNo % 3) == 0) && 
		((iNo % 5) == 0)
	)
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
	
	bRet = Check(iValue);
	if(bRet == true)
	{
		printf("%d is divisible by 3 & 5 \n", iValue);
	}
	else
	{
		printf("%d is NOT divisible by 3 & 5 \n", iValue);
	}
	
	return (0);
}
