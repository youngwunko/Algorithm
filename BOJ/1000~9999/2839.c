#include <stdio.h>

int main(void)
{
    int sugar;
    int i, j, three, five;
    int flag = 0;

    scanf("%d", &sugar);

    five = sugar / 5;
    j = five;

    for(i = 0; i <= j; i++){
        three = (sugar-five*5) / 3;
        if((sugar-five*5) % 3 == 0){
            flag = 1;
            break;
        }
        else{
            five--;
        }
    }

    if(flag == 1){
        printf("%d\n", three + five);
    }
    else{
        printf("-1\n");
    }

    return 0;
}
