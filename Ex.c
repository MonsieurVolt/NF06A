#include <stdio.h>
#include <stdlib.h>
void Matrix_write(int M, int N, float **Matrix, char fileName[])
{
    FILE *ptrFile;
    ptrFile = fopen(fileName, "w");
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fprintf(ptrFile, "%f ", Matrix[i][j]);
        }
        fprintf(ptrFile, "\n");
    }
    fclose(ptrFile);
};
void Matrix_Sum(int N, char fileName[])
{
    FILE *file;
    file = fopen(fileName, "a+");
    float v1[100];

    float v2[100];
    for (int i = 0; i < N; i++)
    {
        fscanf(file, "%f", &v1[i]);
    }
    for (int j = 0; j < N; j++)
    {
        fscanf(file, "%f", &v2[j]);
    }
    for (int i = 0; i < N; i++)
    {
        fprintf(file, "%f ", v1[i] + v2[i]);
    }
    fclose(file);
}
void Ex1()
{
    char name[15];
    printf("Enter the name of the file : \n");
    scanf("%s", name);
    int N, M;
    printf("Enter the number of vectors\n");
    scanf("%d", &M);
    printf("Enter the length of the vectors\n");
    scanf("%d", &N);
    float **Matrix;
    Matrix = (float **)malloc(M * sizeof(float));
    for (int i = 0; i < M; i++)
    {
        Matrix[i] = (float *)malloc(N * sizeof(float));
        for (int j = 0; j < N; j++)
        {
            printf("Enter the line %d col %d \n", i, j);
            scanf("%f", &Matrix[i][j]);
        }
    }
    Matrix_write(M, N, Matrix, name);
    // FILE *file;
    // file = fopen("test.txt", "r");
    // float tab[100];
    // int j = 0;
    // while (feof(file) == 0)
    // {
    //     fscanf(file, "%f", &tab[j]);
    //     j++;
    // }
    // fclose(file);
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("%f\n", tab[i]);
    // }
    Matrix_Sum(N, name);
}

typedef enum
{
    Loaned,
    Available
} bookState;
typedef struct
{
    int day;
    int month;
    int year;
} date;
typedef struct
{
    char author[20];
    char title[100];
    char rib[9];
    int year;
    char editor[20];
    bookState state;
    date loanDate;

} LibBook;
LibBook GetInfos()
{
    LibBook book;
    printf("Enter the name of the author : \n");
    scanf("%s", book.author);
    printf("Enter the title of the book\n");
    scanf("%s", book.title);
    printf("Enter the rib of the book\n");
    scanf("%s", book.rib);
    printf("Enter the year of the book\n");
    scanf("%d", &book.year);
    printf("Enter the editor of the book\n");
    scanf("%s", book.editor);
    printf("Enter 1 if the book is Aviable or 0 if not\n");
    int n;
    scanf("%d", &n);
    if (n)
    {
        book.state = Available;
    }
    else
    {
        book.state = Loaned;
    }
    if (book.state == Loaned)
    {
        printf("Enter the loandate\n");
        printf("Enter the year of the Loan\n");
        scanf("%d", &book.loanDate.year);
        printf("Enter the month of the loan\n");
        scanf("%d", &book.loanDate.month);
        printf("Enter the day of the loan\n");
        scanf("%d", &book.loanDate.day);
    }
    return book;
};
LibBook *readInfos()
{
    char name[20];
    printf("Enter the name of the file : \n");
    scanf("%s", name);
    int nb;
    FILE *file;
    file = fopen(name, "r");
    fscanf(file, "%s", &nb);
    LibBook *arrBook;
    arrBook = (LibBook *)malloc(nb * sizeof(LibBook));

    for (int i = 0; i < nb; i++)
    {
        fscanf(file, "%s\n%s\n%s\n%d\n%s\n%d\n%d %d %d", arrBook[i].author, arrBook[i].title, arrBook[i].rib, &arrBook[i].year, arrBook[i].editor, &arrBook[i].state, &arrBook[i].loanDate.year, &arrBook[i].loanDate.month, &arrBook[i].loanDate.day);
    }
    printf("%d", arrBook[0].loanDate.month);
    fclose(file);
}
void Ex2()
{
    // int nb;
    // printf("Enter the number of books you want to enter\n");
    // scanf("%d", &nb);
    // char fileName[40];
    // printf("Enter the name of the file : \n");
    // scanf("%s", fileName);
    // FILE *file;
    // file = fopen(fileName, "w+");
    // fprintf(file, "%d\n", nb);
    // for (int i = 0; i < nb; i++)
    // {
    //     LibBook book;
    //     book = GetInfos();
    //     fprintf(file, "%s\n%s\n%s\n%d\n%s\n%d\n%d %d %d\n", book.author, book.title, book.rib, book.year, book.editor, book.state, book.loanDate.year, book.loanDate.month, book.loanDate.day);
    // }
    // fclose(file);
    readInfos();
}

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
