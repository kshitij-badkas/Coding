// input ->  row :  6 , col : 6
/*

*	
*	*	
*	*	*	
*	*	*	*	

*/

// almost O(N/2)

#include <stdio.h>

void Display(int iRow, int iCol)
{
	int i = 0, j = 0;

	if(iRow != iCol)
	{
		printf("Rows and Cols should be same - whenever we want Diagonal");
		return;
	}

	for(i = 1; i <= iRow; i++)
	{
		for(j = 1; j <= i ; j++)	// optimized - save no. of iterations 	
		{
			printf("*\t");
		}
		printf("\n");
	}
}

int main()
{
	int iValue1 = 0, iValue2 = 0;

	printf("Enter no. of rows : \n");
	scanf("%d", &iValue1);

	printf("Enter no. of cols : \n");
	scanf("%d", &iValue2);

	Display(iValue1, iValue2);

	return (0);
}
