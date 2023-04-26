#include <stdio.h>

int CountSmall(char *Str)
{
	int iSmall = 0;
	while(*Str != '\0')
	{
		if(*Str >= 'a' && *Str <= 'z')
		{
			iSmall++;
		}
		Str++;
	}
	return(iSmall);
}

int main()
{
	char Arr[20];
	int iRet = 0;
	
	printf("Enter string :\n");
	scanf("%[^'\n']s", Arr);

	iRet = CountSmall(Arr);

	printf("Small Case letters are : %d\n", iRet);


	return (0);
}
