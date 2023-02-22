#include <stdio.h>
#include <time.h>


int main() {
    // Exercise 1
    printf("Exercise 1 :  \n");
    printf("Hello World!\n");
    time_t now;
    time(&now);

    struct tm *local = localtime((&now));
    printf("Today is %02d/%02d/%d\n", local->tm_mday,local->tm_mon+1, local->tm_year+1900);
    local = localtime(&now);
    char MYTIME[20];
    strftime(MYTIME,sizeof(MYTIME),"%U",local);
    printf("This week number is : %s\n",  MYTIME);
    printf("My email addresse is : florian.ducept@utt.fr\n");


    
    }