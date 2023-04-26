#include<iostream>

using namespace std;

int main()
{
	enum Marvellous_Batches { PPA = 0, LB = 1, LSP = 2, Python = 3 };
	
	const int Fees[] = { 15000, 16000, 17000, 18000 };
	const float Duration[] = { 3.5, 4.0, 3.5, 4.0 };
	int choice = 0;
	
	cout << "Select the batch you want you join :" << endl;
	cout << "0 : PPA \n";
	cout << "1 : LB \n";
	cout << "2 : LSP \n";
	cout << "3 : Python \n";
	
	cin >> choice;
	
	switch(choice)
	{
		case PPA :
			cout << "Thanks for joining PPA \n";
			cout << "Duration is : " << Duration[PPA] << endl;
			cout << "FEES is : " << Fees[PPA] << endl;
			break;
			
		case LB :
			cout << "Thanks for joining LB \n";
			cout << "Duration is : " << Duration[LB] << endl;
			cout << "FEES is : " << Fees[LB] << endl;
			break;
			
		case LSP :
			cout << "Thanks for joining LSP \n";
			cout << "Duration is : " << Duration[LSP] << endl;
			cout << "FEES is : " << Fees[LSP] << endl;
			break;
		
		case Python :
			cout << "Thanks for joining Python \n";
			cout << "Duration is : " << Duration[Python] << endl;
			cout << "FEES is : " << Fees[Python] << endl;
			break;
		
		default :
			cout << "Invalid batch \n";
			break;
	}
	
	cout << "Thanks very much for visiting. \n";
	
	return 0;
}
