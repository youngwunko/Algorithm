#include <stdio.h>

int room_person(int floor, int room)
{
    int person = 0, i;

    if(floor == 0)
    {
        person = room;
    }
    else
    {
        for(i = 1; i <= room; i++)
            person += room_person(floor-1, i);
    }

    return person;
}

int main(void)
{
    int T, k, n, i;
    scanf("%d", &T);

    for(i = 0; i < T; i++)
    {
        scanf("%d%d", &k, &n);
        printf("%d\n", room_person(k, n));
    }
    return 0;
}
