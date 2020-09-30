#include <cstdio>
#include <algorithm>

using namespace std;

int cost[1001][3];
int sum[1001][3] = { (0, 0, 0) };

int main(void)
{
	int N;
	scanf("%d", &N);


	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &cost[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + cost[i][0];
		sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + cost[i][1];
		sum[i][2] = min(sum[i - 1][0], sum[i - 1][1]) + cost[i][2];
	}

	int min_cost = min(sum[N][0], sum[N][1]);
	min_cost = min(sum[N][2], min_cost);
	printf("%d\n", min_cost);

	return 0;
}
