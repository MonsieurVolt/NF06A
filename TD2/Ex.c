#include <stdio.h>
#include <math.h>

void Ex1()
{
    float a, b, c;
    printf("Enter the three terms, a,b and c : ");
    scanf("%f %f %f", &a, &b, &c);
    printf("\n");
    float d = b * b - 4 * a * c;
    if (d < 0)
    {
        printf("There are no solutions of the equation\n");
    }
    else if (d == 0)
    {
        printf("There is one solution on the equation it is : %f\n", -b / (2.0 * a));
    }
    else
    {
        printf("The equation get two solutions, the first one is %f and the second one is %f\n", (-b + sqrt(d)) / 2.0 * a, (-b - sqrt(d)) / 2.0 * a);
    }
};
int prime(int n)
{
    if (n == 2)
        return 1;
    else
    {
        int k = 2;
        int z = 1;
        while (k < n)
        {
            while ((prime(k) == 0) && (k < n - 1))
            {
                k++;
            };
            if (n % k == 0)
            {
                z = 0;
                k++;
            }
            else
                k++;
        };
        return z;
    };
};

void Ex2()
{
    printf("1 is a prime number\n");
    for (int i = 3; i < 50; i++)
    {
        int isPrime = 1;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                isPrime = 0;
            }
        }
        if (isPrime)
        {
            printf("%d is a prime number\n", i);
        }
    }
};
// generic function
#define maxi(a, b) (a > b) ? a : b
void Ex3(int arr[], int nb)
{
    if (nb == 0)
    {
        printf("Invalid number of elements inside the array\n");
    }
    else
    {
        int curr = arr[0];
        for (int i = 0; i < nb; i++)
        {
            curr = maxi(curr, arr[i]);
        }
        printf("The maximum of the array is %d\n", curr);
    }
};
int containsZero(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 10)
    {
        return 0;
    }
    if (n % 10 == 0)
    {
        return 1;
    }
    return containsZero((int)(n / 10));
};
void Ex4()
{
    if (containsZero(1239045433))
    {
        printf("This number contains zero in his decimal form\n");
    }
    else
    {
        printf("This number don't contains zero in his decimal form\n");
    }
};
int fiboRec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n <= 2)
    {
        return 1;
    }
    return fiboRec(n - 1) + fiboRec(n - 2);
};
void Ex5()
{
    int n;

    printf("Enter the length of fibo you want : ");
    scanf("%d", &n);
    printf("In iterative : \n");
    if (n == 0)
    {
        printf("0\n");
    }
    if (n == 1)
    {
        printf("1\n");
    }
    int a = 1, b = 1, c = 2;
    printf("The serie is the following : \n");
    for (int i = 2; i < n + 2; i++)
    {
        printf("%d\n", a);
        int memo = c;
        c += b;
        a = b;
        b = memo;
    }
    printf("In recursive : \n");
    printf("%d\n", fiboRec(n));
};
int palinRec(char word[], int length, int i)
{
    if (i == 0)
    {
        return 1;
    }
    return word[i] == word[length - i - 1] && palinRec(word, length, i - 1);
};
void Ex6()
{
    printf("Enter your word : \n");
    int length = 0;
    char word[50];
    scanf("\n");
    while ((word[length] = getchar()) != '\n')
    {
        length++;
    }
    printf("In iterative : \n");
    int middle = length / 2;
    int isPalin = 1;
    for (int i = 0; i < middle; i++)
    {
        printf("%c  = %c\n", word[i], word[length - i - 1]);
        if (word[i] != word[length - i - 1])
        {
            isPalin = 0;
        }
    }
    if (isPalin)
    {
        printf("This word is a palindrome\n");
    }
    else
    {
        printf("this word isn't a palindrome\n");
    }
    printf("In recursive : \n");
    if (palinRec(word, length, length / 2))
    {
        printf("The word  is a palindrome\n");
    }
    else
    {
        printf("The word isn't a palindrome\n");
    }
};
void Ex17()
{
    int sum = 0;
    printf("Enter the expression : \n");
    scanf("\n");
    char c;
    char number[10];
    int lengthnumber = 0;
    short nextNumberSign = 1;
    int nextNumber;
    while ((c = getchar()))
    {
        if (c == ' ' || c == '\n')
        {
            if (lengthnumber != 0)
            {

                for (int i = 0; i < lengthnumber; i++)
                {

                    nextNumber += (int)(number[i] - '0') * (int)pow(10, lengthnumber - 1 - i);
                }
                sum += nextNumberSign * nextNumber;
                nextNumberSign = 1;
                nextNumber = 0;
                lengthnumber = 0;
            }
            if (c == '\n')
            {
                break;
            }
        }
        if (c == '-')
            nextNumberSign = -1;
        if (c >= '0' && c <= '9')
        {
            number[lengthnumber] = c;
            lengthnumber++;
        }
    }
    printf("The sum is : %d\n", sum);
};
int main()
{
    int a = 1;
    while (a)
    {
        int nb;
        printf("Which exercise do you want to solve ? ");
        scanf("%d", &nb);
        switch (nb)
        {
        case 1:
            Ex1();
            break;
        case 2:
            Ex2();
            break;
        case 3:
            int arr[5] = {1, 5, 3, 9, 4};
            Ex3(arr, 5);
            break;
        case 4:
            Ex4();
            break;

        case 5:
            printf("In iterative : \n");
            Ex5();
        case 6:
            Ex6();
        case 17:
            Ex17();
        default:
            printf("Exit...\n");
            a = 0;
            break;
        }
    }
}