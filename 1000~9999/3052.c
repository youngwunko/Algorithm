#include <stdio.h>

int main(void)
{
    int remainder[42] = {0};
    int i, num, diff = 0;

    for(i = 0; i < 10; i++)
    {
        scanf("%d", &num);
        if(remainder[num%42] == 0)
        {
            remainder[num%42]++;
            diff++;
        }
    }
    printf("%d\n", diff);
    return 0;
}
