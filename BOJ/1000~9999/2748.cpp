#include <cstdio>

long long d[100];

long long fibonacci(int x)
{
	if (x == 0) return 0;
	if (x == 1) return 1;
	if (d[x] != 0) return d[x];
	return d[x] = fibonacci(x - 1) + fibonacci(x - 2);
}

int main(void)
{
	int num;
	d[0] = 0;
	d[1] = 1;
	scanf("%d", &num);
	printf("%lld\n", fibonacci(num));
	return 0;
}
