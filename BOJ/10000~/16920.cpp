#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M, P;
int map[1001][1001];
int isused[1001][1001];
int chance[10];
int ans[10];
queue<pair<int, int> > q[10];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main(void)
{
	int s;
	cin >> N >> M >> P;
	for (int i = 1; i <= P; i++)
	{
		cin >> s;
		chance[i] = s;
	}

	string input;
	for (int x = 0; x < N; x++)
	{
		cin >> input;
		for (int y = 0; y < M; y++)
		{
			if (input[y] == '.')
				continue;
			else if (input[y] == '#')
			{
				map[x][y] = -1;
			}
			else
			{
				int num = input[y] - '0';
				map[x][y] = num;
				isused[x][y] = 1;
				q[num].push({ x, y });
				ans[num]++;
			}
		}
	}

	while (1)
	{
		int flag = 0;
		for (int p = 1; p <= P; p++)
		{
			if (q[p].empty())
				continue;
			int now_dist = isused[q[p].front().first][q[p].front().second];
			while (!q[p].empty())
			{
				if (now_dist + chance[p] == isused[q[p].front().first][q[p].front().second])
					break;

				int tx = q[p].front().first;
				int ty = q[p].front().second;
				q[p].pop();

				for (int i = 0; i < 4; i++)
				{
					int nx = tx + dx[i];
					int ny = ty + dy[i];
					if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if (map[nx][ny] == 0)
					{
						map[nx][ny] = p;
						isused[nx][ny] = isused[tx][ty] + 1;
						q[p].push({ nx, ny });
						ans[p]++;
						flag = 1;
					}
				}
			}
		}
		if (flag == 0)
			break;
	}

	for (int i = 1; i <= P; i++)
		cout << ans[i] << " ";
	return 0;
}