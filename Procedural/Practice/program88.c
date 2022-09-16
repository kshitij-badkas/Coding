// input ->  row :  4 , col : 4
/*
	* 	* 	*	 *
	* 	* 	*	 *
	* 	* 	*	 *
	* 	* 	*	 *
*/

#include <stdio.h>

void Display(int iRow, int iCol)
{
	int iCnt_Rows = 0, iCnt_Cols = 0;

	for(iCnt_Rows = 1; iCnt_Rows <= iRow; iCnt_Rows++)
	{
		for(iCnt_Cols = 1; iCnt_Cols <= iCol; iCnt_Cols++)
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
