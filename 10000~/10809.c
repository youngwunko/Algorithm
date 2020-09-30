#include <stdio.h>
#include <string.h>

int main(void)
{
    int alphabet[26];
    int i;
    char word[100];

    scanf("%s", word);
    for(i = 0; i < 26; i++)
    {
        alphabet[i] = -1;
    }

    for(i = 0; i < strlen(word); i++)
    {
       if(alphabet[(int)word[i] - 97] == -1)
           alphabet[(int)word[i] - 97] = i;
    }

    for(i = 0; i < 26; i++)
    {
        printf("%d ", alphabet[i]);
    }
    return 0;
}
