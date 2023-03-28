#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef float *ui;
typedef struct
{
    char name[100];
    float gradeM[2];
    float gradeF[2];
    float gradeA[2];
} Student;
ui getVector()
{
    int n;
    printf("Enter the size of array : \n");
    scanf("%d", &n);
    ui tab = (ui)malloc(sizeof(float) * (n + 1));
    tab[0] = n;
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the element : \n");
        scanf("%f", &tab[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%f\n", tab[i]);
    }
    return tab;
};
ui sumVector(ui v1, ui v2, int len)
{
    ui tab = malloc(sizeof(float) * len);
    for (int i = 1; i <= len; i++)
    {
        tab[i] = v1[i] + v2[i];
    }
    return tab;
};
ui subVector(ui v1, ui v2, int len)
{
    ui tab = malloc(sizeof(float) * len);
    for (int i = 1; i <= len; i++)
    {
        tab[i] = v1[i] - v2[i];
    }
    return tab;
};
ui scalar(ui v1, ui v2, int len)
{
    ui tab = malloc(sizeof(float) * len);
    for (int i = 1; i <= len; i++)
    {
        tab[i] = v1[i] * v2[i];
    }
    return tab;
};
void Ex1()
{
    ui tab1 = getVector();
    ui tab2 = getVector();
    ui resultSum = sumVector(tab1, tab2, tab1[0]);
    ui resultSub = subVector(tab1, tab2, tab1[0]);
    ui resultScalar = scalar(tab1, tab2, tab1[0]);
    for (int i = 1; i <= tab1[0]; i++)
    {
        printf("%f\n", resultSub[i]);
    }
};
void sortName(Student *tab, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int idMin = i;
        for (int j = i + 1; j < len; j++)
        {

            if (strcmp(tab[j].name, tab[idMin].name) < 0)
            {
                idMin = j;
            }
        }
        if (idMin != i)
        {

            Student memo = tab[i];
            tab[i] = tab[idMin];
            tab[idMin] = memo;
        }
    }
};
void sortGrade(Student *tab, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int idMax = i;
        for (int j = i + 1; j < len; j++)
        {

            if (tab[j].gradeA > tab[idMax].gradeA)
            {
                idMax = j;
            }
        }
        if (idMax != i)
        {

            Student memo = tab[i];
            tab[i] = tab[idMax];
            tab[idMax] = memo;
        }
    }
};
void Ex2()
{
    int n;
    printf("Enter the number of students : \n");
    scanf("%d", &n);
    Student *tab = malloc(sizeof(Student) * n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name \n");
        scanf(" ");
        scanf("%[^\n]%*c", tab[i].name);
        printf("Enter the midterm exam grade : \n");
        scanf("%f", tab[i].gradeM);
        printf("Enter the final exam grade : \n");
        scanf("%f", tab[i].gradeF);
        *tab[i].gradeA = 0.4 * (*tab[i].gradeM) + 0.6 * (*tab[i].gradeF);
    }
    sortGrade(tab, n);
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", tab[i].name);
    }
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
        default:
            printf("Exit...\n");
            a = 0;
            break;
        }
    }
    return 0;
}