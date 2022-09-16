#include<iostream>

using namespace std;

class Arithmetic
{
	public: 
	
	//characteristics
	int iNo1;
	int iNo2;
	
	//behaviours
	
	Arithmetic()	//default constructor
	{
		cout<<"Inside default constructor.\n";
		iNo1 = 0;
		iNo2 = 0;
	}
	
	Arithmetic(int A, int B)	//parameterized constructor
	{
		cout<<"Inside parameterized constructor.\n";
		iNo1 = A;
		iNo2 = B;
	}

	~Arithmetic()	//destructor	
	{
		cout<<"Inside destructor.\n";
	}
	
	int Addition()
	{
		int iAns = 0;
		iAns = iNo1 + iNo2;
		return iAns;
	}
	
	int Subtraction()
	{
		int iAns = 0;
		iAns = iNo1 - iNo2;
		return iAns;
	}
};

int main(void)
{
	int iValue1 = 0, iValue2 = 0, iRet = 0;
	
	cout<<"Enter fisrt number : \n";
	cin>>iValue1;
	
	cout<<"Enter secund number : \n";
	cin>>iValue2;
		
	Arithmetic obj1;
	Arithmetic obj2(iValue1, iValue2); //paav bhaji with extra butter ani taak
	
	iRet = obj2.Addition();
	cout<<"Addition : "<<iRet<<"\n";
	
	iRet = obj2.Subtraction();
	cout<<"Subtraction : "<<iRet<<"\n";

    return 0;
}
