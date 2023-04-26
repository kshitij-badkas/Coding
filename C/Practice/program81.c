#include <stdio.h>

void Display(int iNo)
{
	int iCnt = 0;

	if(iNo < 0)
	{
		iNo = -iNo;
	}

	for(iCnt = 1; iCnt <= iNo; iCnt++)
	{
		printf("*\t");
	}
}

int main()
{
	int iValue = 0;

	printf("Enter no. of elements : \n");
	scanf("%d", &iValue);

	Display(iValue);

	return (0);
}
