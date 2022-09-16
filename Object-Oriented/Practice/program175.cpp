#include <iostream>
using namespace std;

int Count(char *str)
{
	int iCnt = 0;
	while(*str != '\0')
	{
		if((*str == 'l') || ((*str == 'L')))
		{
			iCnt++;
		}
		str++;
	}

	return (iCnt);
}

int main()
{
	int iRet = 0;
	char Arr[20];

	cout << "Enter a string : " << endl;
	cin.getline(Arr, 20);

	iRet = Count(Arr);	// Count(100);
	cout << "Count of 'l' & 'L' is : " << iRet << endl;
	return (0);
}
