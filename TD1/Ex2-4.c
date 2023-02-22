#include <stdio.h>

void operation(int a,int b) {
        printf("the sum is : %d\nthe difference is : %d\nthe product is: %d\nthe quotient is : %.3f\n"
        "the remainder of the division is : %d\n",a+b,a-b,a*b,a/(float)b,a%b);
    }
int main()
{
    int i = 1;
    int j = 5;
    printf("Excercise 2  : \n");
    // Division de j par i
    //  I can see with the breakpoint that the problem is on the printf line as there is a zero division error

    printf("Division de j par i = %d\n", j / i);
    printf("Exercise 3 : \n");
    printf("Size of int : %d bytes \nSize of short %d bytes \nSize of char : %d bytes\nSize of float :"
    " %d bytes\nSizeof double : %d bytes", sizeof(int), sizeof(short),sizeof(char),sizeof(float),sizeof(float));

    printf("\nExercicse 4 : \n");
    operation(5,8);
    return 0;
}