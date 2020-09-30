#include <cstdio>

using namespace std;

int factorial(int num)
{
    if(num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int main(void)
{
    int N;
    scanf("%d", &N);

    if(N == 0)
        printf("1\n");
    else
        printf("%d\n", factorial(N));
    return 0;
}
