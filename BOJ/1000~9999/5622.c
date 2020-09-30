#include <stdio.h>

int main(void)
{
    char number[16];
    int alphabet[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5,
                        6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    int result = 0, i;

    scanf("%s", number);
    for(i = 0; i < number[i] != '\0'; i++)
    {
        result += alphabet[number[i]-65] + 1;
    }
    printf("%d\n", result);
    return 0;
}
