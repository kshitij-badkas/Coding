#include <iostream>
using namespace std;

bool strcmpX(char *src, char *dest)
{
	while((*src != '\0') && (*dest != '\0'))
	{
		if(*src != *dest)
		{
			break;
		}
		src++;
		dest++;
	}

	if((*src == '\0') && (*dest == '\0'))
	{
		return (true);
	}
	else
	{
		return (false);
	}
}

int main()
{
	bool bRet;
	char Arr[20], Brr[20];

	cout << "Enter a string 1 : " << endl;
	cin.getline(Arr, 20);

	cout << "Enter a string 2 : " << endl;
	cin.getline(Brr, 20);

	bRet = strcmpX(Arr, Brr);
	if(bRet == true)
	{
		cout << "Strings are Equal\n";
	}
	else
	{
		cout << "Strings are NOT Equal\n";
	}

	return (0);
}
