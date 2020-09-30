#include <stdio.h>

int main(void)
{
    int i, num;
    double sum = 0, score, max;

    scanf("%d", &num);
    scanf("%lf", &max);
    sum = max;

    for(i = 0; i < num - 1; i++){
        scanf("%lf", &score);
        sum += score;
        if(score > max){
            max = score;
        }
    }
    printf("%lf\n", sum * 100 / max / (double)num);
    return 0;
}
