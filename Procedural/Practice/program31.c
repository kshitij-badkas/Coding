#include <stdio.h>

void DisplayNonFactors(int iNo)
{
	auto int iCnt = 0;
	
	// Updater
	if(iNo < 0)
	{
		iNo = -iNo;
	}

	for(iCnt = 1; iCnt < iNo; iCnt++)
	{
		if((iNo % iCnt) != 0)
		{
			printf("%d\n", iCnt);
		}
	}
}

int main()
{	
	int iValue = 0;
	
	printf("Enter no. : \n");
	scanf("%d", &iValue);

	DisplayNonFactors(iValue);

	return (0);
}


// Time Complexity : O(N/2) -> Big O Notation (Order of)
