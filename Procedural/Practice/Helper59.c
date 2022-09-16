#include "Header59.h"

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
