#include <stdio.h>

void Display(char *str)
{
	if(*str != '\0')
	{
		printf("%c\n", *str);
		Display(str++);		// post-increment --> code will not run as exprected
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
