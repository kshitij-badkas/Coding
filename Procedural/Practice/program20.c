// Program to display 1 to 5 on screen
// Output 1 2 3 4 5

#include <stdio.h>

void Display(int iNo)
{
	int iCnt = 0;
	
	// Updater
	if(iNo < 0)
	{
		iNo = -iNo;
	}
	
	/*
	for (iCnt = 1; iCnt <= iNo; iCnt++)
	{
		printf("%d \n", iCnt);
	}
	*/
	
	iCnt = 1;
	while(iCnt <= iNo)
	{
		printf("%d \n", iCnt);	
		iCnt++;
	}
}

int main()
{
	int iValue = 0;
	
	printf("Enter no. \n");
	scanf("%d", &iValue);
	printf("**********\n");
	
	Display(iValue);	
	
	return (0);
}
