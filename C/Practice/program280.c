#include <stdio.h>

void Display(char *str)
{
	if(*str != '\0')
	{
		printf("%s\n", str);
		Display(str+1);		// Tail Recursion
	}
}

int main()
{
	char Arr[20];
	
	printf("Enter string :\n");
	scanf("%[^'\n']s", Arr);

	Display(Arr);
	return (0);
}
