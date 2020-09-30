#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

char maze[102][102];
int dist[102][102];
#define X first
#define Y second

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > q;
	int nx[4] = { 1, -1, 0, 0 };
	int ny[4] = { 0, 0, 1, -1 };
	int N, M;
	bool flag = 0;
	cin >> N >> M;
	cin.ignore();

	string input;
	for (int i = 0; i < N; i++) {
		getline(cin, input);
		for (int j = 0; j < M; j++) {
			maze[i][j] = input[j];
		}
	}

	for (int i = 0; i < N; i++) fill(dist[i], dist[i] + M, -1);

	dist[0][0] = 1;
	q.push({ 0, 0 });

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = cur.X + nx[k];
			int ty = cur.Y + ny[k];

			if (tx < 0 || tx >= N || ty < 0 || ty >= M) continue;
			if (dist[tx][ty] != -1 || maze[tx][ty] == '0') continue;
			q.push({ tx, ty });
			dist[tx][ty] = dist[cur.X][cur.Y] + 1;
		}
	}
	cout << dist[N-1][M-1] << "\n";
	return 0;
}
