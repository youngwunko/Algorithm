#include <cstdio>

long long arr[101];

long long seq(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (x == 3) return 1;
	if (x == 4) return 2;
	if (x == 5) return 2;
	if (arr[x] != 0) return arr[x];
	return arr[x] = seq(x - 1) + seq(x - 5);
}

int main(void)
{
	int T;
	scanf("%d", &T);

	while (T--)
	{
		int N;
		scanf("%d", &N);

		printf("%lld\n", seq(N));
	}
	return 0;
}
