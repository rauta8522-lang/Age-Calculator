#include <stdio.h>
#include <time.h>

int main() {
    int bd, bm, by;
    int cd, cm, cy;
    int ageY, ageM, ageD;

    time_t t;
    struct tm *tm_info;

    time(&t);
    tm_info = localtime(&t);

    cd = tm_info->tm_mday;
    cm = tm_info->tm_mon + 1;
    cy = tm_info->tm_year + 1900;

    printf("Current Date: %02d-%02d-%d\n", cd, cm, cy);

    printf("Enter your Birth Date (DD MM YYYY): ");
    scanf("%d %d %d", &bd, &bm, &by);

    if (bd > cd) {
        cm--;
        cd += 30;
    }

    if (bm > cm) {
        cy--;
        cm += 12;
    }

    ageD = cd - bd;
    ageM = cm - bm;
    ageY = cy - by;

    printf("\nYour Age is: %d Years %d Months %d Days\n",
           ageY, ageM, ageD);

    return 0;
}
