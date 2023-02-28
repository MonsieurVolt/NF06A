#include <stdio.h>
struct maxMin
{
    double max;
    double min;
};
void operation(int a, int b)
{
    printf("the sum is : %d\nthe difference is : %d\nthe product is: %d\nthe quotient is : %.3f\n"
           "the remainder of the division is : %d\n",
           a + b, a - b, a * b, a / (float)b, a % b);
};
void mySwap(float *a, float *b)
{
    float memo = *a;
    *a = *b;
    *b = memo;
};
void charSum(char a, char b)
{
    printf("The sum of %c and %c gives : %c\n", a, b, (char)((int)(a) + (int)(b) - (int)('A') + 1));
    printf("The difference of %c and %c gives : %c\n", a, b, (char)((int)(a) - (int)(b) + (int)('A') - 1));
};
struct maxMin myMax(double a, double b)
{
    struct maxMin result;
    result.max = a > b ? a : b;
    result.min = a < b ? a : b;
    return result;
};
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
           " %d bytes\nSizeof double : %d bytes",
           sizeof(int), sizeof(short), sizeof(char), sizeof(float), sizeof(float));

    operation(5, 8);
    float k = 5.5;
    float l = 8.9;
    printf("Before the swap I get : i = %f ; j = %f\n", k, l);
    mySwap(&k, &l);
    printf("After the swap I get : i = %f ; j = %f\n", k, l);
    charSum('F', 'D');
    struct maxMin mm = myMax(10, 15);
    printf("The max between %.1f and %.1f is  : %.1f and the min is : %.1f", 10.f, 15.f, mm.max, mm.min);
    return 0;
}