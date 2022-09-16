#include <stdio.h>

void Display(int Arr[])
{
	register int iCnt = 0;

	printf("Elements of array : \n");

	for(iCnt = 0; iCnt < 5; iCnt++)
	{
		printf("%d\n", Arr[iCnt]);
	}
}

int main()
{
	register int iCnt = 0; 
	auto int Brr[5];

	printf("Enter elements : \n");

	for(iCnt = 0; iCnt < 5; iCnt++)
	{
		scanf("%d", &Brr[iCnt]);
	}

	Display(Brr);			// Display(100) -> 100 : Base address of array
		
	return (0);
}
