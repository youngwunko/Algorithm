#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[200];

    while(fgets(str, sizeof(str), stdin))
    {
        //str[strlen(str)-1] = '\0';
        printf("%s", str);
    }
    return 0;
}
