#include<iostream>
using namespace std;

class Demo
{
	private:
			int y;

	public: 
		int i, j;		// instance variable (non-static)
		static int x;	// class variable (static)

		Demo(int a = 10, int b = 20)
		{
			cout<<"Inside parameteried constructor with default args\n";
			cout<<this->i<<"\n";
			cout<<this->j<<"\n";
			this->i = a;
			this->j = b;
			cout<<"AFTER - Inside parameteried constructor with default args\n";
			cout<<this->i<<"\n";
			cout<<this->j<<"\n";

			this->y = 5000;
		}

		//void fun(Demo *this, int no)
		void fun(int no)
		{
			cout<<"Inside non-static fun()\n";
			cout<<this->i<<"\n";
			cout<<this->j<<"\n";
		}

		static void gun(int value)
		{
			cout<<"Inside static gun() : "<<value<<"\n";
			cout<<"Inside static gun() : y = "<<y<<"\n";
			
			// cout<<this->i<<"\n";  //Error

		}

		
};

int Demo::x = 30;
//int Demo::y = 100;

int main(void)
{
	cout<<Demo::x<<"\n";
	Demo::gun(100);

	Demo::gun(8000);

	//cout<<Demo::y<<"\n";

	cout<<"Inside main()\n";

	Demo obj(11);

	Demo::x = 50;
	//cout<<"Changed x here\n";
	cout<<Demo::x<<"\n";


	obj.fun(21); //fun(&obj, 21);
	cout<<"Size of obj : "<<sizeof(obj)<<"\n";
	cout<<obj.i<<"\n";
	cout<<obj.j<<"\n";

	obj.gun(200); // Demo::gun(200) -> Allowed

	return 0;
}

