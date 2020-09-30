#include <stdio.h>

int main(void)
{
    int A, B;

    while(1)
    {
        if(scanf("%d%d", &A, &B) == EOF)
            break;
        printf("%d\n", A+B);
    }
    return 0;
}
