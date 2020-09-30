#include <stdio.h>

int main(void)
{
	int a, b, c;
	int i;
	int result, remain;
	int num[10] = { 0 };

	scanf("%d%d%d", &a, &b, &c);
	result = a * b * c;

	while (result != 0)
	{
		remain = result % 10;
		num[remain]++;
		result /= 10;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", num[i]);
	}
	return 0;
}
