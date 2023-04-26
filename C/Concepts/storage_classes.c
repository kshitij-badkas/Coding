#include<stdio.h>

float fs;
int main()
{
	auto int b;
	printf("b = %d\n",b);
	
	static int s;
	printf("s = %d\n",s);
	
	printf("fs = %f\n",fs);
	
	char c = '\0';
	printf("c = %c\n",c);
	
	return 0;
}