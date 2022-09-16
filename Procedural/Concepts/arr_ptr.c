#include<stdio.h>


int main()
{
	//register auto int ra;
	//int a = 100;
	//int *iptr = &a;
	//void *ptr = &iptr;
	//printf("%d \n", *iptr);
	//printf("%d \n", *ptr);
	
	/*
	int arr[] = {10, 20, 30, 40, 50 };
	int *p = arr;
	
	printf("%d \n", p);
	printf("%d \n", *p);
	printf("%d \n", arr);
	printf("%d \n", &arr);
	printf("%d \n", sizeof(arr));
	*/
	
	int no = 10;
	int *ptr = NULL;
	ptr = &no;
	printf("%d \n", no);
	printf("%d \n", *ptr);
	
	*ptr = 11;
	printf("%d \n", no);
	printf("%d \n", *ptr);
	

	
	
	
	//Gharchyanna bolun sanga kay jhala te
	
	
	/*
	int no = 10;
	int *p = &no;
	int **s = &p;
	
	printf("%d \n", p);
	printf("%d \n\n", *p);
	
	printf("%d \n", s);
	printf("%d \n", *s);
	printf("%d \n\n", **s);
	
	
	double drr[] = {12.3, 1.23, 12.8};
	double *r = &(drr[2]);
	printf("%d\n", &(drr[0]));
	printf("%d\n", &(drr[1]));
	printf("%d\n", &(drr[2]));
	printf("%d\n", &(drr[3]));
	printf("%lf\n", (drr[4]));
	*/
	
	/*
	float value = 3.14;
	float *p = &value;
	float *q = p;
	float ans = *p + *q;
	
	printf("%d\n", &p);
	printf("%d\n", p);
	//printf("%f\n", q);
	printf("%f\n", *q);
	printf("%f\n", ans);
	*/
	
	return 0; 					//OS la sanga ki sagla nit jhala
	

	
}// block chi shevat

