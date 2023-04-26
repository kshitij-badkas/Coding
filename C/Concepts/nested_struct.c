#include<stdio.h>

//auto int a = 10;
struct Demo
{

	int i;
	float f;
	struct Demo2
	{

		int i2;
		float f2;
	}d2obj;
}obj;

struct Demo3
{
	struct Demo obj2;
	struct Demo2 d2obj2;
};

int main()
{
	struct Demo obj1;
	struct Demo2 dobj2;
	struct Demo3 d3obj3;
	
	printf("******\n");
	printf("Size of struct is %d \n", sizeof(dobj2));
	
	
	return 0; 					//OS la sanga ki sagla nit jhala
	
}// block chi shevat

