#include<stdio.h>
int main()
{
	int a = 0, b = 0;

	printf("******\n");
	printf("enter a: \n");
	scanf("%d", &a);
	printf("enter b: \n");
	scanf("%d", &b);
	
	if( a == b)
	{
		printf("a = b \n");
	}
	else if( a < b)
	{
		printf("b is greater than a \n");
	}
	else
	{
		printf("a is greater than b \n");
	}
	
	
	return 0; 					//OS la sanga ki sagla nit jhala
	
}// block chi shevat

