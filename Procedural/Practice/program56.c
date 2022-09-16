// a,b -> a^b
#include <stdio.h>

typedef unsigned long int ULONG;

ULONG Power(int iNo1, int iNo2)
{
	register int iCnt = 0;
	auto ULONG lMult = 1;

	for(iCnt = 1; iCnt <= iNo2; iCnt++)
	{
		lMult = lMult * iNo1;
	}
	return (lMult);	
}

int main()
{
	auto int iValueA, iValueB = 0;
	auto ULONG lRet = 0;		// datatype modifier

	printf("Enter no. A \n");
	scanf("%d", &iValueA);

	printf("Enter no. B \n");
	scanf("%d", &iValueB);

	lRet = Power(iValueA, iValueB);
	printf("%ld\n", lRet);
	
	return (0);
}
