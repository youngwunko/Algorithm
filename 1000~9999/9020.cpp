#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int main(void)
{
	int T, N;
	int num1, num2;
	int diff;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		diff = N;

		int* prime = new int[N];

		for (int j = 2; j < N; j++)
		{
			prime[j] = 0;
		}

		for (int m = 2; m < N; m++)
		{
			if (prime[m] == 0)
			{
				for (int n = 2; n < N / m; n++)
				{
					prime[m*n] = 1;
				}
			}
		}

		vector<int> arr;
		for (int k = 2; k < N; k++)
		{
			if (prime[k] == 0)
			{
				arr.push_back(k);
			}
		}
		delete[] prime;

		for (int p = 0; p < arr.size(); p++)
		{
			for (int q = 0; q < arr.size(); q++)
			{
				if (((arr.at(p) + arr.at(q)) == N) && abs(arr.at(p)-arr.at(q)) < diff)
				{
					num1 = arr.at(p);
					num2 = arr.at(q);
					diff = abs(arr.at(p)-arr.at(q));
				}
			}
		}

		if (num1 > num2)
		{
			int temp = num1;
			num1 = num2;
			num2 = temp;
		}
		printf("%d %d\n", num1, num2);
	}
	return 0;
}
