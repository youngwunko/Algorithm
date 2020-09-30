#include <stdio.h>

int main(void)
{
	int i, count;
	char num[101] = { 0 };
	int sum = 0;

	scanf("%d", &count);
	scanf("%s", num);

	for (i = 0; i < count; i++) {
		sum += num[i] - 48;
	}

	printf("%d\n", sum);
	return 0;
}
