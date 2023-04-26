// input ->  row :  4 , col : 4
/*

A       
B       B
C       C       C
D       D       D       D

*/

// O(N/2)

#include <stdio.h>

void Display(int iRow, int iCol)
{
	int i = 0, j = 0;
	char ch = '\0';

	for(i = 1; i <= iRow; i++)
	{
		for(j = 1, ch = 'a'; j <= i ; j++, ch++)
		{
			printf("%c\t", ch);
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
