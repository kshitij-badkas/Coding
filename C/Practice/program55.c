#include <stdio.h>
#include <stdbool.h>

bool CheckPalindrome(int iNo)
{
	int iDigit = 0;
	int iRev = 0;

	if(iNo < 0)
	{
		iNo = -iNo;
	}

	int iTemp = iNo;

	while(iNo > 0)
	{
		iDigit = iNo % 10;
		iRev = iRev * 10 + iDigit;
		iNo = iNo / 10;
	}
	
	if(iRev == iTemp)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int iValue = 0;
	bool bRet = false;

	printf("Enter no. \n");
	scanf("%d", &iValue);

	bRet = CheckPalindrome(iValue);
	if(bRet == true)
	{
		printf("%d is a palindrome\n", iValue);
	}
	else
	{
		printf("%d is NOT a palindrome\n", iValue);
	}

	return (0);
}
