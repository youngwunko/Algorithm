#include <stdio.h>

int main(void)
{
    int test_case, num, prime = 0, i, j;

    scanf("%d", &test_case);
    for(i= 0; i < test_case; i++)
    {
        scanf("%d", &num);
        if(num != 1)
        {
            prime++;
            for(j = 2; j < num; j++)
            {
                if(num % j == 0)
                {
                    prime--;
                    break;
                }
            }
        }
        else if(num == 2)
            prime++;
    }
    printf("%d\n", prime);
    return 0;
}
