#include <stdio.h>

int main(void)
{
    char word[101];
    int i;

    scanf("%s", word);

    for(i = 0; word[i] != NULL; i++){
        printf("%c", word[i]);
        if((i+1) % 10 == 0){
            printf("\n");
        }
    }
}
