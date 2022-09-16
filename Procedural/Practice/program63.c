#include <stdio.h>

int main()
{
	register int iCnt = 0; 
	auto int Arr[5];

	printf("Enter elements : \n");

	for(iCnt = 0; iCnt < 5; iCnt++)
	{
		scanf("%d", &Arr[iCnt]);
	}
		
	printf("Elements of array : \n");

	for(iCnt = 0; iCnt < 5; iCnt++)
	{
		printf("%d\n", Arr[iCnt]);
	}

	return (0);
}
