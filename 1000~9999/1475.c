#include <stdio.h>

int main(void)
{
	int N, set = 0, i;
	int num[10] = { 0 };

	scanf("%d", &N);
	while (N / 10 != 0)
	{
		num[N % 10]++;
		N /= 10;
	}
	num[N % 10]++;

	if ((num[6] + num[9]) % 2 == 0)
		num[6] = (num[6] + num[9]) / 2;
	else
		num[6] = ((num[6] + num[9]) / 2) + 1;

	for (i = 0; i < 9; i++)
	{
		if (set < num[i])
			set = num[i];
	}
	printf("%d\n", set);
	return 0;
}
