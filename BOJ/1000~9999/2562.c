#include <stdio.h>

int main(void)
{
    int num, max, max_i = 1, i;

    scanf("%d", &max);

    for(i = 2; i <= 9; i++)
    {
        scanf("%d", &num);
        if(num > max)
        {
            max = num;
            max_i = i;
        }
    }
    printf("%d\n", max);
    printf("%d\n", max_i);
    return 0;
}
