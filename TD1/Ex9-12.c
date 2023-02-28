#include <stdio.h>
#include <math.h>
void Ex9BinToDec(unsigned short b)
{
    unsigned short result = 0;
    for (int i = 0; i < 16; i++)
    {
        result += (0b1 & b) * pow(2, i);
        b = b >> 1;
    }
    printf("The conversion in decimal is %d\n", result);
};
void Ex9DecToBin(unsigned short b)
{
    unsigned short result = 0b0;
    unsigned short arr[17];
    int i = 0;
    while (b > 0)
    {
        unsigned short r = b % 2;
        b = b - r;
        b = b / 2;
        arr[i] = r;
        result = result | r << i;
        i++;
    }
    printf("The conversion to binary is : \n");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", arr[j]);
    }
    printf("\n");
    printf("%d\n", result);
};
void Ex10DecToOct(unsigned short b)
{
    unsigned short arr[17];
    int i = 0;
    while (b > 0)
    {
        unsigned short r = b % 8;
        b = b - r;

        b = b / 8;
        arr[i] = r;
        i++;
    }
    printf("The conversion to octal is : \n");
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", arr[j]);
    }
    printf("\n");
};
void Ex11(int number)
{
    printf("The number %d in hexadecimal is : %X\n", number, number);
};
void Ex12()
{
    short maxShort = (short)~(0b1 << sizeof(short) * 8 - 1);
    int maxInt = ~(0b1 << sizeof(int) * 8 - 1);
    char maxChar = (0b1 << sizeof(char) * 8 - 1);
    long a = ~((long)0b1 << sizeof(long) * 8 - 1);
    printf("The maximal limit of int is : %d\nThe minimum limit of int is : %d\n", maxInt, ~maxInt);
    printf("The maximal limit of short is : %d\nThe minimum limit of short is : %d\n", maxShort, ~maxShort);
    printf("The maximum limit of char is : %d\nThe minimum limit of char is : %d\n", maxChar, ~maxChar);
    printf("The maximum limit of long is : %ld\nThe minimum limit of long is : %ld\n", a, ~a);
};
int main()
{
    printf("Ex9 : \n");
    Ex9BinToDec(0b110);
    Ex9DecToBin(15);
    printf("Ex10 : \n");
    Ex10DecToOct(13);
    printf("Ex11 : \n");
    Ex11(14);
    printf("Ex12 : \n");
    Ex12();
};