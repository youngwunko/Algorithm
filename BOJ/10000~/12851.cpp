#include <cstdio>
#include <queue>

using namespace std;
#define MAX 100000 + 1
int min_sec;
int method = 0;
bool visit[MAX];

void BFS(int N, int K)
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(N, 0));
	visit[N] = true;

	while (!Q.empty())
	{
		int cur_loc = Q.front().first;
		int cur_sec = Q.front().second;
		Q.pop();
		visit[cur_loc] = true;

		if (min_sec && (cur_loc == K) && (cur_sec == min_sec))
		{
			method++;
		}

		if (!min_sec && (cur_loc == K))
		{
			min_sec = cur_sec;
			method++;
		}

		if (cur_loc + 1 < MAX && visit[cur_loc + 1] == false)
			Q.push(make_pair(cur_loc + 1, cur_sec + 1));
		if (cur_loc - 1 >= 0 && visit[cur_loc - 1] == false)
			Q.push(make_pair(cur_loc - 1, cur_sec + 1));
		if (cur_loc * 2 < MAX && visit[cur_loc * 2] == false)
			Q.push(make_pair(cur_loc * 2, cur_sec + 1));
	}

}

int main(void)
{
	int N, K;

	scanf("%d%d", &N, &K);
	BFS(N, K);
	printf("%d\n", min_sec);
	printf("%d\n", method);
	return 0;
}
