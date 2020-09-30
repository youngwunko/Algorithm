#include <stdio.h>

int main(void)
{
    char letter;

    while((letter = getchar()) != -1){
        putchar(letter);
    }
    return 0;
}
