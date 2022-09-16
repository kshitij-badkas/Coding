// Complexity O(2N)

#include <stdio.h>

void Display(int iNo)
{
	int iCnt = 0;

	for(iCnt = -iNo; iCnt <= iNo; iCnt++)
	{
		printf("%d\t", iCnt);
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
