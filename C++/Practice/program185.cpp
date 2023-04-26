#include <iostream>
using namespace std;

void strrevX(char *str)
{
	char *start = NULL, *end = NULL;
	char temp = '\0';

	start = str;
	end = str;

	while(*end != '\0')
	{
		end++;
	}
	end--;		// ek ghar maage ana

	// swapping
	while(start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;

		start++;
		end--;
	}
}

int main()
{
	char Arr[20];

	cout << "Enter a string : " << endl;
	cin.getline(Arr, 20);

	strrevX(Arr);
	cout << "String after reverse  : "  << Arr << endl;
	return (0);
}
