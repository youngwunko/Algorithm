#include <stdio.h>

int main(void)
{
    int test_case, repeat, i, j, m;
    char S[21];

    scanf("%d", &test_case);

    for(i = 0; i < test_case; i++)
    {
        scanf("%d%s", &repeat, S);
        //scanf("%s", S);
        for(j = 0; S[j] != '\0'; j++)
        {
            for(m = 0; m < repeat; m++)
                printf("%c", S[j]);
        }
        printf("\n");
    }
    return 0;
}
