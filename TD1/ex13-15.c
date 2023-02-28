#include <stdio.h>

void Ex13()
{
    int *c, *d;
    int a[4] = {2, 4, 6, 5};
    int b[4] = {1, 6, 7, 8};
    c = a;
    d = b;
    int *temp = c;
    c = d;
    d = temp;
    for (int i = 0; i < 4; i++)
    {
        printf("The content of a is  : %d and the content of b is  : %d \n", c[i], d[i]);
    }
    // we can do this without looping, we have to use pointers
}

void Ex14()
{
    char a[10];
    printf("I read a string of 10 char and give their ASCII number : \n");
    for (int i = 0; i < 10; i++)
    {
        a[i] = getchar();
    }
    for (int i = 0; i < 10; i++)
    {
        printf("The ASCII code of %c is %d\n", a[i], (int)a[i]);
    }
}
void Ex15(short a, short b)
{
    printf("The binary AND between %d and %d is %d\n", a, b, a & b);
    printf("The binary OR between %d and %d is : %d\n", a, b, a | b);
    printf("The binary XOR between %d and %d is  : %d\n", a, b, a || b);
    printf("The Ones' complement of %d is  : %d \nThe Ones' complement of %d is : %d\n", a, ~a, b, ~b);
    printf("The lefmost 8 bits of %d are : %d\n", a, a >> 7);
    printf("The rightmost 8 bits of %d are : %d\n", a, a % 256);
}
int main()
{
    printf("Ex13  : \n");
    Ex13();
    printf("Ex14 : \n");
    Ex14();
    printf("Ex15 : \n");
    Ex15(6, 2);
}