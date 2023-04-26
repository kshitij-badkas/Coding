#include<stdio.h>
#include<string.h>

int strlenX(char str[])
{
	int iCnt = 0;
	int iLength = 0;
	
	for(iCnt = 0; str[iCnt] != '\0'; iCnt++)
	{
		iLength++;
	}
	
	return iLength;
}

int strlenXX(char str[])
{
	int iCnt = 0;
	int iLength = 0;
	
	while(str[iCnt] != '\0')
	{
		iCnt++;
		iLength++;
	}
	
	return iLength;
}

int strlenXXX(char *str)
{
	int iCnt = 0;
	//int iLength = 0;
	
	while(*str != '\0')
	{
		iCnt++;
		//iLength++;
		str++;
	}
	
	return iCnt;
}


int main()
{
	char Arr[] = "abcd";
	int iRet = 0;
	
	iRet = strlenXXX(Arr);
	
	printf("Length of Arr - %d \n", strlen(Arr));
	printf("Length of Arr iRet- %d \n", iRet);

	return 0; 					//OS la sanga ki sagla nit jhala
	
}// block chi shevat

