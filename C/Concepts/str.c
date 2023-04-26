#include<stdio.h>
#include<string.h>

int main()
{
	char Arr[5] = {'a', 'b', 'c', 'd', '\0'};
	
	char Brr[5] = "abcd";
	
	printf("%s \n", Arr);
	printf("%s \n", Brr);
	
	printf("Size of Arr - %d \n", sizeof(Arr));
	printf("Size of Brr - %d \n", sizeof(Brr));
	
	printf("Length of Arr - %d \n", strlen(Arr));
	printf("Length of Brr - %d \n", strlen(Brr));
	
	return 0; 					//OS la sanga ki sagla nit jhala
	
}// block chi shevat

