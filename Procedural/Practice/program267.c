#include <stdio.h>

void Display(int iNo)
{
	static int i = 0;
	if(i < iNo)
	{
		printf("%c\t", 'a'+i);
		i++;
		Display(iNo);
	}
}

int main()
{
	int iValue = 0;
	
	printf("Enter number :\n");
	scanf("%d", &iValue);

	Display(iValue);

	return (0);
}
