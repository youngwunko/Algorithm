#include <stdio.h>

int main(void)
{
    int num[8];
    int i, flag;

    for(i = 0; i < 8; i++)
    {
        scanf("%d", &num[i]);
    }

    for(i = 0; i < 8; i++)
    {
        if(num[i] != i+1)
        {
            flag = 1;
            break;
        }
        else
            flag = 0;
    }

    if(flag == 0)
    {
        printf("ascending\n");
        return 0;
    }

    for(i = 0; i < 8; i++)
    {
        if(num[i] != 8-i)
        {
            printf("mixed\n");
            return 0;
        }
    }
    printf("descending\n");
    return 0;
}
