#include <cstdio>

int main(void)
{
    int point[4][2];

    scanf("%d%d", &point[0][0], &point[0][1]);
    scanf("%d%d", &point[1][0], &point[1][1]);
    scanf("%d%d", &point[2][0], &point[2][1]);

    if(point[0][0] == point[1][0])
    {
        point[3][0] = point[2][0];
    }
    else
    {
        if(point[1][0] == point[2][0])
            point[3][0] = point[0][0];
        else
            point[3][0] = point[1][0];
    }

    if(point[0][1] == point[1][1])
    {
        point[3][1] = point[2][1];
    }
    else
    {
        if(point[1][1] == point[2][1])
            point[3][1] = point[0][1];
        else
            point[3][1] = point[1][1];
    }

    printf("%d %d\n", point[3][0], point[3][1]);
    return 0;
}
