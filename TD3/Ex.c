#include <stdio.h>
#include <math.h>
#define SIZE 100
void mySwap(int *table1, int *table2, int id1, int id2)
{
    int memo = table1[id1];
    table1[id1] = table2[id2];
    table2[id2] = memo;
};
void Ex2()
{
    printf("Enter your text : \n");
    int length = 0;
    int nbUpper = 0;
    int nbLower = 0;
    int nbSpaces = 0;
    char c;
    scanf("\n");
    while ((c = getchar()) != '\n')
    {
        if (c == ' ')
            nbSpaces++;
        if (c >= 'A' && c <= 'Z')
            nbUpper++;
        if (c >= 'a' && c <= 'z')
            nbLower++;
    }
    printf("Lower : %d ; Upper : %d ; Spaces : %d\n", nbLower, nbUpper, nbSpaces);
};
void opMatrices(int cm, int lm, int m1[][3], int m2[][3], int *ma, int *ms, int *mm)
{
    for (int i = 0; i < lm; i++)
    {
        for (int j = 0; j < cm; j++)
        {

            ma[i * cm + j] = m1[i][j] + m2[i][j];
            ms[i * cm + j] = m1[i][j] - m2[i][j];
            mm[i * cm + j] = m1[i][j] * m2[i][j];
        }
    }
};
void Ex3()
{
    int nbLig = 2;
    int nbCol = 3;
    int m1[2][3] = {2, 3, 7, 6, 4, 5};
    int m2[2][3] = {5, 4, 8, 7, 9, 3};
    int mm[6], ma[2][3], ms[6];
    opMatrices(3, 2, m1, m2, (int *)ma, (int *)ms, (int *)mm);
    printf("the result of adding the two matrix gives : \n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", ma[i][j]);
        }
        printf("\n");
    }
};
void Ex5()
{
    int tab[SIZE];
    printf("Enter the number of int you want to insert : \n");
    int nbN;
    scanf("%d", &nbN);
    for (int i = 0; i < nbN; i++)
    {
        printf("Enter the number to insert : \n");
        int nb;
        scanf("%d", &nb);
        int id = i;
        if (i == 0)
        {
            tab[0] = nb;
        }
        else
        {
            while (id > 0 && tab[id - 1] > nb)
            {

                tab[id] = tab[id - 1];
                id--;
            }

            tab[id] = nb;
        }
    }
    for (int i = 0; i < nbN; i++)
    {
        printf("%d ", tab[i]);
    }
}
void Ex9()
{
    double matrix1[SIZE][SIZE];
    double matrix2[SIZE][SIZE];
    int nbl, nbc;
    printf("Enter the number of lig and col : \n");
    scanf("%d", &nbl);
    scanf("%d", &nbc);
    for (int i = 0; i < nbl; i++)
    {
        for (int j = 0; j < nbc; j++)
        {
            double n;
            printf("Enter the number for the lig %d and the col %d of the matrix: \n", i, j);
            scanf("%lf", &matrix1[i][j]);
        }
    }
    printf("Enter the real which multiply the matrix : \n");
    double real;
    scanf("%lf", &real);
    for (int i = 0; i < nbl; i++)
    {
        for (int j = 0; j < nbc; j++)
        {
            matrix2[j][i] = matrix1[i][j] * real;
        }
    }
    for (int i = 0; i < nbc; i++)
    {
        for (int j = 0; j < nbl; j++)
        {
            printf("%lf ", matrix2[i][j]);
        }
        printf("\n");
    }
};
// void Ex6() {
//     int matrix1[SIZE][SIZE];
//     int nbl = 4, nbc = 2;
//     printf("Enter the number of lig and col : \n");
//     scanf("%d", &nbl);
//     scanf("%d", &nbc);
//     for (int i = 0; i < nbl; i++)
//     {
//         for (int j = 0; j < nbc; j++)
//         {

//             printf("Enter the number for the lig %d and the col %d of the matrix: \n", i, j);
//             scanf("%d", &matrix1[i][j]);
//         }
//     }
//     for (int i =0; i < nbl; i++) {
//         int idMin = 0;
//         for (int j = 0; j < nbc; j++) {
//             if (matrix1[i][j] < matrix1[i][idMin]) {
//                 idMin = j;
//             }
//         }
//         int isLower = 1;
//         for (int j = 0; j < nbc; j++) {
//             if (j != i && matrix1[j][idMin] <= matrix1[])
//         }
//     }
// }
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
            int arr1[5] = {1, 2, 3, 4, 5};
            int arr2[5] = {6, 7, 8, 9, 10};
            printf("Before the Swap : \n");
            for (int i = 0; i < 5; i++)
            {
                printf("arr1 : %d ; arr2 : %d\n", arr1[i], arr2[i]);
            }
            mySwap(arr1, arr2, 2, 4);
            printf("After the Swap : \n");
            for (int i = 0; i < 5; i++)
            {
                printf("arr1 : %d ; arr2 : %d\n", arr1[i], arr2[i]);
            }
            break;
        case 2:
            Ex2();
            break;
        case 3:
            Ex3();
            break;
        case 5:
            Ex5();
            break;
        case 9:
            Ex9();
            break;
        default:
            printf("Exit...\n");
            a = 0;
            break;
        }
    }
    return 0;
}