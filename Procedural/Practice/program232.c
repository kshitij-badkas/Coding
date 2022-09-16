#include <stdio.h>

//	-> 123
//	<- 321

void DisplayI(int no)			// Iterative
{
	while(no != 0)
	{
		printf("%d\t", no % 10);
		no = no / 10;
	}
}

void DisplayR(int no)
{
	if(no != 0)
	{
		no = no / 10;
		DisplayR(no);			// Recursive
		printf("%d\t", no % 10);

	}
}

int main()
{
	DisplayR(123);

	return (0);
}
