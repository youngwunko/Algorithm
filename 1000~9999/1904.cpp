#include <cstdio>

int d[1000001];

int fibonacci(int x)
{
	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= x; i++)
	{
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	}
	return d[x];
}

int main(void)
{
	int N;
	scanf("%d", &N);

	printf("%d\n", fibonacci(N));
	return 0;
}
