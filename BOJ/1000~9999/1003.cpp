#include <cstdio>

int d[42];

int fibonacci(int x)
{
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(d[x] != 0) return d[x];
    return d[x] = fibonacci(x-1) + fibonacci(x-2);
}

int main(void)
{
    d[0] = 1;
    d[1] = 0;
    d[2] = 1;

    int T;
    scanf("%d", &T);

    while(T--)
    {
        int num;
        scanf("%d", &num);

        if(num == 0)
            printf("1 0\n");
        else
            printf("%d %d\n", fibonacci(num-1), fibonacci(num));
    }
    return 0;
}
