// Program to display 5 times Hello on screen

#include <stdio.h>

// Demonstration of Sequence

void Display(int iNo)		// Definition
{
	int iCnt = 0;
	/*
	//Filter
	if(iNo < 0)
	{
		printf("Enter positive value \n");
		return;
	}
	*/
	// Updater
	if(iNo < 0)
	{
		iNo = -iNo;
	}
	
	for(iCnt = 0; iCnt < iNo; iCnt++)
	{
		printf("Hello \n");
	}
}

int main()			// Declaration
{
	int iValue = 0;
	
	printf("Enter how many times to display : \n");
	scanf("%d", &iValue);
	
	Display(iValue);		// Function call
	
	return (0);
}


