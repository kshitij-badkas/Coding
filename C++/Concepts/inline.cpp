#include<iostream>
using namespace std;

class Demo
{
	public:
		
		// 0 characteristics
		// 1 behaviour
		
		int Add(int no1, int no2)
		{
			int ans = 0;
			ans = no1 + no2;
			return ans;
		}
};

int main(void)
{
	Demo obj;
	int ret = 0;
	
	ret = obj.Add(10, 11);
	
	cout << ret << "\n";			// 21
	
	cout << sizeof(obj) << "\n"; 	// 1
	
    return 0;
}
