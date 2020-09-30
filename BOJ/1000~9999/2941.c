#include <stdio.h>

int main(void)
{
    char word[101];
    int result = 0, i;

    scanf("%s", word);
    for(i = 0 ; word[i] != '\0'; i++)
    {
        result++;

        if(word[i] == '=')
        {
            if(word[i-1] == 'c' || word[i-1] == 's')
                result--;
            else if(word[i-1] == 'z')
            {
                if(i == 1)
                    result--;
                else if(word[i-2] == 'd')
                    result -= 2;
                else
                    result--;
            }
        }
        else if(word[i] == '-')
        {
            if(word[i-1] == 'c' || word[i-1] == 'd')
                result--;
        }
        else if(word[i] == 'j' && i != 0)
        {
            if(word[i-1] == 'l' || word[i-1] == 'n')
                    result--;
        }
    }
    printf("%d\n", result);
    return 0;
}
