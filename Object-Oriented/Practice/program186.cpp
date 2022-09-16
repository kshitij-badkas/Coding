#include <iostream>
using namespace std;

void strcpyX(char *src, char *dest)
{
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

	cout << "Enter a string : " << endl;
	cin.getline(Arr, 20);

	strcpyX(Arr, Brr);
	cout << "String befor copy  : "  << Arr << endl;
	cout << "String after copy  : "  << Brr << endl;
	return (0);
}
