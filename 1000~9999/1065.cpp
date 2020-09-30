#include <cstdio>
#include <vector>

using namespace std;

bool diff(int num)
{
	vector<int> part, diff_num;

	while (1)
	{
		if (num == 0)
			break;
		else
		{
			part.push_back(num % 10);
			num /= 10;
		}
	}

	for (int i = 0; i < part.size() - 1; i++)
	{
		diff_num.push_back(part.at(i) - part.at(i + 1));
	}

	for (int i = 0; i < diff_num.size() - 1; i++)
	{
		if (diff_num.at(i) != diff_num.at(i + 1))
			return false;
	}

	return true;
}

int main(void)
{
	int N, result = 0;
	scanf("%d", &N);

	if (N < 10)
		result = N;
	else
	{
		result = 9;
		for (int i = 10; i <= N; i++)
		{
			if (diff(i) == true)
				result++;
		}
	}

	printf("%d\n", result);
	return 0;
}
