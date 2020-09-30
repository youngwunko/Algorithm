#include <stdio.h>

int main(void)
{
    int yut[4];
    int i;

    for(i = 0; i < 3; i++)
    {
        scanf("%d%d%d%d", &yut[0], &yut[1], &yut[2], &yut[3]);

        switch(yut[0]+yut[1]+yut[2]+yut[3])
        {
            case 0:
                printf("D\n");
                break;
            case 1:
                printf("C\n");
                break;
            case 2:
                printf("B\n");
                break;
            case 3:
                printf("A\n");
                break;
            case 4:
                printf("E\n");
                break;
        }
    }
    return 0;
}
