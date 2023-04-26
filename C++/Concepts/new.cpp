#include<iostream>

using namespace std;

int main(void)
{
	int Arr[10];
	int *p = NULL;
	
	// p = (int*)malloc(sizeof(int) * 10);
	
	p = new int[10];
	if(p == NULL)
	{
		cout<<" Unable to allocate\n";
	}
	else
	{
		cout<<"Jai Ganesh...\n"<<p<<"\n";

	}
	
	//free(p);

	delete []p;
	
	cout<<"Bye Bye...\n"<<p<<"\n";


    return 0;
}
