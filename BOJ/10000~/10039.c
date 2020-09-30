#include <stdio.h>

int main(void)
{
    int result = 0, score, i;

    for(i = 0; i < 5; i++)
    {
        scanf("%d", &score);
        result += (score >= 40 ? score : 40);
    }
    printf("%d\n", result / 5);
    return 0;
}
