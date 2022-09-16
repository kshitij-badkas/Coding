#include <stdio.h>

void DisplayEven(int iNo)
{
	int iDigit = 0;

	if(iNo < 0)
	{
		iNo = -iNo;
	}

	while(iNo > 0)
	{
		iDigit = iNo % 10;
		if((iDigit % 2) == 0)
		{
			printf("%d\n", iDigit);
		}
		iNo = iNo / 10;
	}
}

int main()
{
	int iValue = 0;
	printf("Enter no. \n");
	scanf("%d", &iValue);

	DisplayEven(iValue);
	
	return (0);
}
