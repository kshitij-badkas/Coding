#include <iostream>
using namespace std;

void strcatX(char *src, char *dest)
{
	while(*dest != '\0')
	{
		dest++;
	}
	
	while(*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
}

int main()
{
	char Arr[20], Brr[20];

	cout << "Enter a string 1 : " << endl;
	cin.getline(Arr, 20);

	cout << "Enter a string 2 : " << endl;
	cin.getline(Brr, 20);

	strcatX(Arr, Brr);
	cout << "String befor concat  : "  << Arr << endl;
	cout << "String after concat  : "  << Brr << endl;
	return (0);
}
