#include <stdio.h>

int main(void)
{
    int test_case, i, j, temp;
    int num[1000] = {0};

    scanf("%d", &test_case);

    for(i = 0; i < test_case; i++)
    {
        scanf("%d", &num[i]);
    }

    for(i = 0; i < test_case; i++)
    {
        for(j = i+1; j < test_case; j++)
        {
            if(num[i] > num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    for(i = 0; i < test_case; i++)
    {
        printf("%d\n", num[i]);
    }
    return 0;
}
