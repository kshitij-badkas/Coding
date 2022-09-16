#include <stdio.h>

void Display(int iPtr[])
{
	register int iCnt = 0;

	printf("Elements of array : \n");

	for(iCnt = 0; iCnt < 5; iCnt++)
	{
		printf("%d\n", *(iPtr + iCnt));
	}
}

int main()
{
	register int iCnt = 0; 
	auto int Arr[5];

	printf("Enter elements : \n");

	for(iCnt = 0; iCnt < 5; iCnt++)
	{
		scanf("%d", &Arr[iCnt]);
	}

	Display(Arr);			// Display(100) -> 100 : Base address of array
		
	return (0);
}
