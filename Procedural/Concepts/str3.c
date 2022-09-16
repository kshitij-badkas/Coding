#include<stdio.h>

int main()
{
	char Arr[5] = "abcd";
	char *ptr = Arr;
	int i = 0;
	while(*ptr != '\0')
	{
		printf("i = %d : %c\n",i, *ptr);
		ptr++;
		i++;
	}
	
	return 0; 					//OS la sanga ki sagla nit jhala
	
}// block chi shevat

