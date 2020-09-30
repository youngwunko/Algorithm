#include <stdio.h>

int main(void)
{
    int N, i = 1;

    scanf("%d", &N);
    if(N == 1)
        printf("1\n");
    else
    {
        while(1)
        {
            if((N - 1 > 3 * (i-1) * i) && N - 1 <= 3 * i * (i+1))
                break;
            else
                i++;
        }
        printf("%d\n", i+1);
    }
    return 0;
}
