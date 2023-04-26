#include <stdio.h>

int SumDigits(int iNo)
{
	static int iSum = 0;
	// or
	// auto int iDigit = 0; 
	if(iNo != 0)
	{
		// or 
		// iDigit = iNo % 10;
		iSum = iSum + (iNo % 10);
		iNo = iNo / 10;
		SumDigits(iNo);
	}
	return (iSum);
}

int main()
{
	int iValue = 0, iRet = 0;
	
	printf("Enter number :\n");
	scanf("%d", &iValue);

	iRet = SumDigits(iValue);

	printf("Sum of Digits : %d\n", iRet);


	return (0);
}
