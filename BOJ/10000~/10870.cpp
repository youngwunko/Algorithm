#include <cstdio>

using namespace std;

int fibonacci(int num)
{
    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else
        return fibonacci(num - 1) + fibonacci(num - 2);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    printf("%d\n", fibonacci(n));
    return 0;
}
