#include <iostream>
using namespace std;

void strcatX(char *src, char *dest)
{
	while(*src != '\0')
	{
		src++;
	}
	
	while(*dest != '\0')
	{
		*src = *dest;
		src++;
		dest++;
	}
	*src = '\0';
}

int main()
{
	char Arr[20], Brr[20];

	cout << "Enter a string 1 : " << endl;
	cin.getline(Arr, 20);

	cout << "Enter a string 2 : " << endl;
	cin.getline(Brr, 20);

	strcatX(Arr, Brr);
	cout << "String after concat  : "  << Brr << endl;
	cout << "String befor concat  : "  << Arr << endl;
	return (0);
}
