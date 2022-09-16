#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int size = 0;
	int *ptr = NULL;
	int icnt = 0;
	
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
	printf("Enter elements : \n");
	for(icnt = 0; icnt < size; icnt++)
	{
		scanf("%d", &ptr[icnt]);
	}
	
	printf("Entered elements -> : \n");
	for(icnt = 0; icnt < size; icnt++)
	{
		printf("%d\n", ptr[icnt]);
	}
	
	free(ptr); //step 3: free the memory
	
	ptr = NULL;
	
	return 0;
}


