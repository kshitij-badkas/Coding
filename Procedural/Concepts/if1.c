#include<stdio.h>

int main()
{
	int marks = 0;
	
	printf("Enter marks : \n");
	scanf("%d", &marks);
	printf("your entered marks : %d \n", marks);
	
	if(marks >= 60)
	{
		printf("First class \n");
	}
	else
	{
		printf("Not First class \n");
	}
	
    return 0;
}
