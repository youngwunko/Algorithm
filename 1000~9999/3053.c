#include <stdio.h>

int main(void)
{
    double R;

    scanf("%lf", &R);
    printf("%.6lf\n", R*R*3.141592653589793238462643);
    printf("%.6lf\n", R*R*2);
    return 0;
}
