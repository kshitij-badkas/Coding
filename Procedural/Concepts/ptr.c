#include<stdio.h>

//auto int a = 10;

int main()
{
	int i = 3;

	int *p = &i;

	int **q = &p;

	printf("******\n");
	printf("%d \n", i);
	printf("%d \n", *p);
	printf("%d \n", *q);
	
	printf("%d \n", sizeof(i));
	printf("%d \n", sizeof(p));
	printf("%d \n", sizeof(*q));
	
	//printf("%d \n\n", brr[4]);	//Gharchyanna bolun sanga kay jhala te
	
	return 0; 					//OS la sanga ki sagla nit jhala
	
}// block chi shevat

