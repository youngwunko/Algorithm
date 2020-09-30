#include <cstdio>
#include <queue>

using namespace std;
#define MAX 1000000 + 1
int min_time = -1;
bool visit[MAX];

void BFS(int F, int S, int G, int U, int D)
{
	queue<pair<int, int> > Q;
	Q.push(make_pair(S, 0));
	visit[S] = true;

	while (!Q.empty())
	{
		int cur_stair = Q.front().first;
		int cur_cnt = Q.front().second;
		Q.pop();

		if (cur_stair == G)
		{
			min_time = cur_cnt;
			return;
		}

		if (cur_stair + U <= F && visit[cur_stair + U] == false)
        {
            Q.push(make_pair(cur_stair + U, cur_cnt + 1));
            visit[cur_stair + U] = true;
        }
		if (cur_stair - D >= 1 && visit[cur_stair - D] == false)
        {
            Q.push(make_pair(cur_stair - D, cur_cnt + 1));
            visit[cur_stair - D] = true;
        }
	}
}

int main(void)
{
	int F, S, G, U, D;

	scanf("%d%d%d%d%d", &F, &S, &G, &U, &D);
	BFS(F, S, G, U, D);

	if (min_time == -1)
		printf("use the stairs\n");
	else
		printf("%d\n", min_time);
	return 0;
}
