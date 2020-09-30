#include <stdio.h>

int main(void)
{
    int x, y, remain;

    scanf("%d%d", &x, &y);

    switch(x){
        case 2:
            y += 3;
            break;
        case 3:
            y += 3;
            break;
        case 4:
            y += 6;
            break;
        case 5:
            y += 1;
            break;
        case 6:
            y += 4;
            break;
        case 7:
            y += 6;
            break;
        case 8:
            y += 2;
            break;
        case 9:
            y += 5;
            break;
        case 11:
            y += 3;
            break;
        case 12:
            y += 5;
            break;
    }

    remain = y % 7;
    switch(remain){
        case 0:
            printf("SUN\n");
            break;
        case 1:
            printf("MON\n");
            break;
        case 2:
            printf("TUE\n");
            break;
        case 3:
            printf("WED\n");
            break;
        case 4:
            printf("THU\n");
            break;
        case 5:
            printf("FRI\n");
            break;
        case 6:
            printf("SAT\n");
            break;
    }
    return 0;
}
