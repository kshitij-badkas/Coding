#include <stdio.h>

//	*	*	*	*

void DisplayI()			// Iterative
{
	auto int iCnt = 1;
	while(iCnt <= 4)
	{
		printf("*\t");
		iCnt++;
	}
}

void DisplayR()
{
	static int iCnt = 1;
	if(iCnt <= 4)
	{
		printf("*\t");
		iCnt++;
		DisplayR();		// Recursive call
	}
}

int main()
{
	DisplayR();

	return (0);
}
