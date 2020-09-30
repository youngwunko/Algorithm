#include <stdio.h>

int main(void)
{
    int test_case, A, B, i;

    scanf("%d", &test_case);
    for(i = 0; i < test_case; i++)
    {
        scanf("%d%d", &A, &B);
        printf("Case #%d: %d\n", i+1, A+B);
    }
    return 0;
}
