#include <stdio.h>

int main(void)
{
    int A, B, C, num;
    scanf("%d%d%d", &A, &B, &C);

    if(B >= C)
    {
        printf("-1\n");
    }
    else
    {
        num = (A / (C - B)) + 1;
        printf("%d\n", num);
    }
    return 0;
}
   
