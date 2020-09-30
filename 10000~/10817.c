#include <stdio.h>

int main(void)
{
    int a, b, c;

    scanf("%d%d%d", &a, &b, &c);

    if(a >= b){
        if(a <= c){
            printf("%d\n", a);
        }
        else if(b >= c){
            printf("%d\n", b);
        }
        else{
            printf("%d\n", c);
        }
    }
    else{
        if(a >= c){
            printf("%d\n", a);
        }
        else if(b >= c){
            printf("%d\n", c);
        }
        else{
            printf("%d\n", b);
        }
    }
    return 0;
}
