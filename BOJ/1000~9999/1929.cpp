#include <cstdio>

int main(void)
{
	int M, N;

	scanf("%d%d", &M, &N);

	int* prime = new int[N+1];

	prime[0] = 1;
	prime[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		prime[i] = 0;
	}

	for (int m = 2; m <= N; m++)
	{
		if (prime[m] == 0)
		{
			for (int n = 2; n <= N / m; n++)
			{
				prime[m*n] = 1;
			}
		}
	}

	for (int k = M; k <= N; k++)
	{
		if (prime[k] == 0)
		{
			printf("%d\n", k);
		}
	}
	delete[] prime;
	return 0;
}
