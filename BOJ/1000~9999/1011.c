#include <stdio.h>
#include <math.h>

int main(void)
{
	int test_case, i, n = 0;
	int x, y;
	int diff;

	scanf("%d", &test_case);
	for (i = 0; i < test_case; i++)
	{
		scanf("%d%d", &x, &y);
		diff = y - x;
		n = (int)sqrt((double)diff);

		if (diff == n * n)
			printf("%d\n", 2*n - 1);
		else if (diff > n*n && diff <= n * n + n)
			printf("%d\n", 2*n);
		else
			printf("%d\n", 2*n + 1);
	}
	return 0;
}
