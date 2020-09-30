#include <stdio.h>
#include <string.h>

int main(void)
{
    char word[1000001];
    int alphabet[26] = {0};
    int i, most = -1, length;
    char result = 0;

    scanf("%s", word);
    length = strlen(word);
    for(i = 0; i < length; i++)
    {
        if(word[i] >= 97)
            alphabet[word[i]-97]++;
        else
            alphabet[word[i]-65]++;
    }

    for(i = 0; i < 26; i++)
    {
        if(alphabet[i] > most)
        {
            most = alphabet[i];
            result = (char)i + 65;
        }
        else if(alphabet[i] == most)
        {
            result = '?';
        }
    }
    printf("%c\n", result);
    return 0;
}
