#include "Header59.h"

int main()
{
	auto int iValueA, iValueB = 0;
	auto ULONG lRet = 0;

	printf("Enter no. A \n");
	scanf("%d", &iValueA);

	printf("Enter no. B \n");
	scanf("%d", &iValueB);

	lRet = Power(iValueA, iValueB);
	printf("%ld\n", lRet);
	
	return (0);
}
