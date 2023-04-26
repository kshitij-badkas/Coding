#include<stdio.h>
// 1 - 8
// 2 - 9
// 3 - 10
// 4 - 11
// 5 - 12

int main()
{
	auto int iStd = 0;
	
	printf("Enter standard : \n");
	scanf("%d", &iStd);
	printf("your entered : %d \n", iStd);
	
	if(iStd == 1)
	{
		printf(" => 8 \n");
	}
	else if(iStd == 2)
	{
		printf(" => 9 \n");
	}
	else if(iStd == 3)
	{
		printf(" => 10 \n");
	}
	else if(iStd == 4)
	{
		printf(" => 11 \n");
	}
	else if(iStd == 5)
	{
		printf(" => 12 \n");
	}
	else
	{
		printf(" Invalid \n");
	}
	
    return 0;
}
