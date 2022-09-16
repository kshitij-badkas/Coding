#include<stdio.h>
// 0 - 10 --- 100
// 10 - 40 --- 500
// 40 ++ --- 300

int main()
{
	auto int iAge = 0;
	
	printf("Enter age : \n");
	scanf("%d", &iAge);
	printf("your entered age : %d \n", iAge);
	
	if((iAge >=0 ) && (iAge <= 10))
	{
		printf("100 \n");
	}
	else if((iAge > 10 ) && (iAge <= 40))
	{
		printf("500 \n");
	}
	else if(iAge > 40)
	{
		printf("300 \n");
	}
	
    return 0;
}
