#include <cstdio>

void prime(int M, int N)
{
	int* prime = new int[N+1];
    int count = 0;

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
			count++;
		}
	}
    printf("%d\n", count);
	delete[] prime;
}

int main(void)
{
    int num;

    while(1)
    {
        scanf("%d", &num);

        if(num == 0)
            break;
        else
            prime(num+1, num*2);
    }
    return 0;
}
