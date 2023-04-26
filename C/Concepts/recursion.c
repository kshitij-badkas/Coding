#include <stdio.h>

void DisplayI(int no)
{
    int i = 1;
    while(i <= no)
    {
        printf("*\n");
        i++;
    }
}

void DisplayR(int no)
{
    static int i = 1;
    if(i <= no)
    {
        printf("*\n");
        i++;
        DisplayR(no);       //recursive call
    }
}

int main()
{
    // DisplayI(11);

    int value = 3;
    DisplayR(value);

    return (0);
}
