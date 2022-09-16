#include <stdio.h>

int Sum(int *Arr, int iSize)
{
	static int iCnt = 0, iSum = 0;

	if(iCnt < iSize)
	{
		iSum = iSum + Arr[iCnt];
		iCnt++;
		Sum(Arr, iSize);
	}
	return (iSum);
}

int main()
{
	int Brr[] = { 10, 20, 30, 40 };
	int iRet = 0;
	
	iRet = Sum(Brr, 4);

	printf("Summation is : %d\n", iRet);

	return (0);
}
