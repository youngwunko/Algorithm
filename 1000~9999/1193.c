#include <stdio.h>

int main(void)
{
    int X, diff, i = 1;

    scanf("%d", &X);
    while(1)
    {
        if(X > i * (i+1) / 2)
            i++;
        else
            break;
    }
    diff = X - (i * (i-1) / 2);

    if(i % 2 == 0)
        printf("%d/%d\n", diff, i + 1 - diff);
    else
        printf("%d/%d\n", i + 1 - diff, diff);
    return 0;
}
