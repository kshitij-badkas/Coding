// input ->  row :  4 , col : 4
/*
	$	*	*	*
	#	$	*	*
	#	#	$	*
	#	#	#	$
*/

// O(N*N)

#include <stdio.h>

void Display(int iRow, int iCol)
{
	int i = 0, j = 0;

	// Filter ---> if row and col nos. are not same For Diagonal
	if(iRow != iCol)
	{
		printf("Invalid input... Row and Column nos. should be same.\n");
		return;
	}
	
	for(i = 1; i <= iRow; i++)
	{
		for(j = 1; j <= iCol ; j++)
		{
			if(i < j)				// Upper triangle
			{
				printf("*\t");
			}
			else if(i > j)			// Lower traingle
			{
				printf("#\t");
			}
			else if(i == j)			// Diagonal
			{
				printf("$\t");
			}
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
