#include <stdio.h>

int main(void)
{
    int num, changed_num;
    int cycle = 1;

    scanf("%d", &num);
    changed_num = num;
    while(1){
        changed_num = (changed_num % 10) * 10 + (changed_num / 10 + changed_num % 10) % 10;

        if(num != changed_num){
            cycle++;
        }
        else{
            break;
        }
    }
    printf("%d\n", cycle);
    return 0;
}
