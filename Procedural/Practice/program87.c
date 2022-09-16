
#include <stdio.h>

void Display(int iNo)
{
	int iCnt = 0;

	for(iCnt = 1; iCnt <= iNo; iCnt++)
	{
		if(iCnt % 2 == 0)
		{
			printf("*\t", iCnt);
		}
		else
		{
			printf("%d\t", iCnt);
		}
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
