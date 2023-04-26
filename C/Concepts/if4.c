#include<stdio.h>
// 1 - 8
// 2 - 9
// 3 - 10
// 4 - 11
// 5 - 12

int main()
{
	auto int iStd = 0;
	
	printf("Enter standard : \n");
	scanf("%d", &iStd);
	printf("your entered : %d \n", iStd);
	
	switch(iStd)
	{
		case 1:
			printf(" => 8 \n");
			break;
			
		case 2:
			printf(" => 9 \n");
			break;
	
		case 3:
			printf(" => 10 \n");
			break;

		case 4:
			printf(" => 11 \n");
			break;
		
		case 5:
			printf(" => 12 \n");
			break;
			
		default :
			printf(" => Invalid \n");
			//break; optional


	}
	
	
	
    return 0;
}
