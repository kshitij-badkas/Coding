#include <stdio.h>

void JewellersPortal(int iWeight)
{
	switch (iWeight)
	{
	case 1:
		printf("Your bill amount : 4,000 \n");
		break;
	
	case 2:
		printf("Your bill amount : 8,000 \n");
		break;
	
	case 5:
		printf("Your bill amount : 20,000 \n");
		break;
	
	case 10:
		printf("Your bill amount : 40,000 \n");
		break;

	default:
		printf("INVALID \n");
		break;
	}
}

int main()
{	
	int iValue = 0;

	printf("Enter the size of Gold coin : ");
	scanf("%d", &iValue);

	JewellersPortal(iValue);

	return (0);
}
