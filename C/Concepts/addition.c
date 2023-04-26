#include<stdio.h>

//Gharakhalcha dukan
int Addition(int no1, int no2)
{
	//block chi suruvat
	int Ans = 0; 				//local variable of Addition
	Ans = no1 + no2; 			//Add kela by ALU
	
	return Ans; 				//Jyane call kela tyala value dya
	
}// block cha shevat

//Ithun program run hoto
int main()
{
	//block chi suruvat
	
	//local variables of main()
	int A = 10, B = 11, C = 0; 	//C mhanje rikami pishvi

	C = Addition(A, B); 		//Function call
	
	printf("%d \n", C); 		//Gharchyanna bolun sanga kay jhala te
	
	return 0; 					//OS la sanga ki sagla nit jhala
	
}// block chi shevat
