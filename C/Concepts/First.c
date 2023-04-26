#include<stdio.h>

//extern int no;  // Declaration of variable
extern int c;  // Declaration of variable
int Addition(int, int);

int main()
{
	c = Addition(10, 20);
    printf("%d\n",c);

    return 0;
}

// gcc  First.c  Second.c   -o   Myexe
// ./Myexe      For Linux or MACOS
// Myexe        For windows