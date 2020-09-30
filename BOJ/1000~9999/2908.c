#include <stdio.h>

int main(void)
{
    int a, new_a, b, new_b;

    scanf("%d%d", &a, &b);
    new_a = (a % 10) * 100;
    a /= 10;
    new_a += (a % 10) * 10;
    a /= 10;
    new_a += a;

    new_b = (b % 10) * 100;
    b /= 10;
    new_b += (b % 10) * 10;
    b /= 10;
    new_b += b;

    if(new_a > new_b)
        printf("%d\n", new_a);
    else
        printf("%d\n", new_b);
    return 0;
}
