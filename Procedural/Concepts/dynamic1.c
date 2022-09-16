#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int size = 0;
	int *ptr = NULL;
	
	printf("Enter number of elements : \n");
	scanf("%d",&size);
	
	ptr = (int *)malloc(size * sizeof(int)); // step 1: allocate the memory
	if(ptr == NULL)
	{
		printf("UNABLE TO ALLOCATE MEMORY. \n");
	}
	else
	{
		printf("SUCCESSFUL MEMORY ALLOCATION. \n");
	}
	
	//step 2 : use the memory
	
	free(ptr); //step 3: free the memory
	
	return 0;
}


