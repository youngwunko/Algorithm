#include <cstdio>

int main(void)
{
    int a, b, c;

    while(1)
    {
        scanf("%d%d%d", &a, &b, &c);

        if(a == 0 && b == 0 && c == 0)
        {
            break;
        }
        else
        {
            int temp;
            if(a > c)
            {
                temp = c;
                c = a;
                a = temp;
            }
            if(b > c)
            {
                temp = c;
                c = b;
                b = temp;
            }

            if((a*a + b*b) == c*c)
                printf("right\n");
            else
                printf("wrong\n");
        }
    }
    return 0;
}
