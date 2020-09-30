#include <cstdio>
#include <vector>

using namespace std;
#define MAX 10000 + 1
bool visit[MAX];

void selfNum(int num)
{
	for (int i = num; i < MAX;)
	{
		int temp = i;

		while (1)
		{
			if (i == 0)
				break;
			else
			{
				temp += i % 10;
				i /= 10;
			}
		}

		if (visit[i] == true)
		{
			return;
		}
		else
		{
			i = temp;
			visit[i] = true;
		}
	}
}

int main(void)
{
	for (int i = 1; i < MAX; i++)
	{
		selfNum(i);
	}

	for (int i = 1; i < MAX; i++)
	{
		if (visit[i] == false)
			printf("%d\n", i);
	}

	return 0;
}
