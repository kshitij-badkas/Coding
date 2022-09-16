#include<iostream>

using namespace std;

int main()
{
	int Input = 0;
	
	//			 0	  1    2    3    4    5    6
	enum Days { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

	enum Days obj;

	obj = Tue;
	
	cout << obj << endl;
	cout << sizeof(obj) << endl;
	
	
	enum Gender { Female = 1, Male = 2 };
	
	cout << "Enter Gender" << endl;
	cout << "1. Female" << endl;
	cout << "2. Male" << endl;
	
	cin >> Input;
	
	switch(Input)
	{
		case Female :
			cout << "Tax free limit is 3,00,000 /-" << endl ;
			break;
			
		case Male :
			cout << "Tax free limit is 2,50,000 /-" << endl;
			break;
			
		default:
			cout << "Invalid gender" << endl;
			break;
	}
	
	return 0;
}
