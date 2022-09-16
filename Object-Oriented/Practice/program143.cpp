#include <iostream>
using namespace std;

class ArrayX
{
	private:
		int *Arr;
		int iSize;
	
	public:
		ArrayX(int iValue)		// Parameterized constructor 
		{
			this->iSize = iValue;
			Arr = new int[iSize];		// Resource
		}

		~ArrayX()
		{
			delete []Arr;		// Deallocate resource
		}

		void Accept()		// void Accept(ArrayX *this)
		{
			int iCnt = 0;
			cout << "Enter elements : " << endl;
			for(iCnt = 0; iCnt < iSize; iCnt++)
			{
				cout << "Enter value of element : " << iCnt+1 << endl;
				cin >> Arr[iCnt];
			}
		}

		void Display()		// void Display(ArrayX *this)
		{
			int iCnt = 0;
			cout << "Elements of array are : " << endl;
			for(iCnt = 0; iCnt < iSize; iCnt++)
			{
				cout << Arr[iCnt] << endl;
			}
		}

		int Summation()
		{
			int iSum = 0, iCnt = 0;
			for(iCnt = 0; iCnt < iSize; iCnt++)
			{
				iSum = iSum + Arr[iCnt];
			}
			return (iSum);
		}
};

int main()
{
	int iRet = 0;

	ArrayX obj1(5);
	obj1.Accept();		// Accept(&obj1)	Accept(100)
	obj1.Display();		// Display(&obj1)	Display(100)

	iRet = obj1.Summation();

	cout << "Addition is : " << iRet << endl;

	return (0);
}