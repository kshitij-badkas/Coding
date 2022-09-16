#include <iostream>
using namespace std;

int CountCapital(char *str)
{
	int iCnt = 0;
	while(*str != '\0')
	{
		if((*str >= 'A') && (*str <= 'Z'))
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

	iRet = CountCapital(Arr);	// Count(100);
	cout << "Count of Capital Letters is : " << iRet << endl;
	return (0);
}
