#include <cstdio>

int prime(int num)
{
    int flag = 0;

    if(num == 1)
    {
        flag = 1;
    }
    else
    {
        for(int i = 2; i < num; i++)
        {
            if(num % i == 0)
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

int main(void)
{
    int M, N, min = 0, sum = 0, flag = 0;

    scanf("%d%d", &M, &N);

    for(int i = M; i <= N; i++)
    {
        if(prime(i) == 0)
        {
            sum += i;
            if(flag == 0)
            {
                min = i;
                flag = 1;
                break;
            }
        }
    }

    for(int j = min + 1; j <= N; j++)
    {
        if(prime(j) == 0)
        {
            sum += j;
        }
    }

    if(min == 0)
    {
        printf("-1\n");
    }
    else
    {
        printf("%d\n%d\n", sum, min);
    }
    return 0;
}
