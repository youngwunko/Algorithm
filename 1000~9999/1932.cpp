#include <cstdio>
#include <algorithm>

using namespace std;

int cost[501][501];
int sum[501][501] = { 0 };

int main(void)
{
	int N;
	scanf("%d", &N);


	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j == 1)
				sum[i][j] = sum[i - 1][j] + cost[i][j];
			else if(j == i)
				sum[i][j] = sum[i - 1][j - 1] + cost[i][j];
			else
				sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + cost[i][j];
		}
	}

	int max_cost = 0;

	for (int i = 1; i <= N; i++)
	{
		max_cost = max(max_cost, sum[N][i]);
	}
	printf("%d\n", max_cost);

	return 0;
}
