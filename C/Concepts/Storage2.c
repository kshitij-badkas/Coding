#include<stdio.h>

// Demo he function cha naw ahe je tumhi kahi pan deau shakata
// %d mhanaje d for decimal
// \n mhanaje new line jyane apan new line war display karato

void Demo()
{
    auto int A = 10;
    A++;    // ++ ne value ekane increment hote
    printf("%d\n",A);
}

void Hello()
{
    static int A = 10;
    A++;    // ++ ne value ekane increment hote
    printf("%d\n",A);
}

int main()
{
    Demo();     // Function call
    Demo();     // Function call

    Hello();
    Hello();

    return 0;
}