#include <iostream>
using namespace std;

void Display(char *str)
{
	while(*str != '\0')
	{
		cout << *str << endl;
		str++;
	}
}

int main()
{
	char Arr[20];

	cout << "Enter a string : " << endl;
	cin >> Arr;

	Display(Arr);		// Display(100);
	
	return (0);
}