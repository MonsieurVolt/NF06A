#include <stdio.h>
#define PI 3.1416
void Ex5()
{
    unsigned short A = 104, B;
    float C = 6.5;
    // add C to A in int format
    A += (unsigned short)C;
    // operate the bitwise complement to A
    A = ~A;
    // operate the bitwise OR
    B = A ^ (A + 2);
    // Casting the type of A
    C = (float)(A << B);
    // Operate the AND operation between A and C
    A = A & (unsigned short)C;
    printf("Value of A : %d ; value of B : %d ; Value of C : %f \n", A, B, C);
    // the result will change as the complement is not the same with int or unsigned
};
void Ex6(unsigned short x, int n, int p)
{
    unsigned short d = x << 17 - p - n;
    d = ~d;
    d = d >> 16 - p;
    d = d << n - 1;
    unsigned short s = x >> n + p - 1;
    s = s << n + p - 1;
    unsigned short e = x << 16 - n + 1;
    e = e >> 16 - n + 1;
    printf("The result with the number %d is %d\n", x, (s | e | d));
};
void Ex7(int B, int H)
{
    int A = (float)1 / 2 * B * H;
    printf("The area of the triangle of base %d and height %d is %d\n", B, H, A);
};
void Ex8(int R, int H)
{
    printf("The value of PI is : %f\n", (float)PI);
    float B = (float)PI * R * R;
    printf("The volume of the cone of area Radius %d and height %d is %.2f", R, H, (float)1 / 3 * B * H);
};
int main()
{
    printf("Exercise 5 : \n");
    Ex5();
    printf("Exercise 6 : \n");
    Ex6(16, 2, 3);
    printf("Exercise 7 : \n");
    Ex7(7, 9);
    printf("Exercise 8 : \n");
    Ex8(5, 10);
}