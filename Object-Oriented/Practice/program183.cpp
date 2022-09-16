#include <iostream>
using namespace std;

void struprX(char *str)
{
	while(*str != '\0')
	{
		if((*str >= 'a') && (*str <= 'z')) 
		{
			*str = *str - 32;
		}
		str++;
	}

}

int main()
{
	int iRet = 0;
	char Arr[20];

	cout << "Enter a string : " << endl;
	cin.getline(Arr, 20);

	struprX(Arr);	// Count(100);
	cout << "String in UPPER case  : "  << Arr << endl;
	return (0);
}
