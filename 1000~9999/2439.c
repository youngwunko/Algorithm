#include <stdio.h>

int main(void)
{
    int i, j, num;
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        for(j = 0; j < num - i - 1; j++){
            printf(" ");
        }
        for(j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
