#include <iostream>
using namespace std;

int strlenX(char *str)
{
	int iCnt = 0;
	while(*str != '\0')
	{
		str++;
		iCnt++;
	}

	return (iCnt);
}

int main()
{
	int iRet = 0;
	char Arr[20];

	cout << "Enter a string : " << endl;
	cin.getline(Arr, 20);

	iRet = strlenX(Arr);	// Display(100);
	cout << "Size of string is : " << iRet << endl;
	return (0);
}
