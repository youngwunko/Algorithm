#include <iostream>
#include <queue>
#include <string>

#define X first
#define Y second
using namespace std;

int map[1003][1003];
int dist[2][1003][1003];
int N, M;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int main(void) {
	cin >> N >> M;

	string input;
	for (int x = 1; x <= N; x++) {
		cin >> input;
		for (int y = 0; y < M; y++) {
			map[x][y + 1] = (input[y] == '0') ? 0 : 1;
		}
	}
	for(int i = 0; i < 2; i++)
		for (int x = 1; x <= N; x++)
			fill(dist[i][x], dist[i][x] + M + 1, -1);

	queue<pair<int, pair<int, int> > > q;

	q.push({ 0, {1, 1} });
	dist[0][1][1] = 0;
	dist[1][1][1] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.Y.X + dx[i];
			int ny = cur.Y.Y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
			if (map[nx][ny] == 1) {
				if (cur.X == 1) continue;
				else {
					if (dist[1][nx][ny] != -1 && dist[1][nx][ny] <= dist[0][cur.Y.X][cur.Y.Y] + 1) continue;
					q.push({ 1, {nx, ny} });
					dist[1][nx][ny] = dist[0][cur.Y.X][cur.Y.Y] + 1;
				}
			}
			else {
				if(dist[cur.X][nx][ny] != -1 && dist[cur.X][nx][ny] <= dist[cur.X][cur.Y.X][cur.Y.Y] + 1) continue;
				q.push({ cur.X, {nx, ny} });
				dist[cur.X][nx][ny] = dist[cur.X][cur.Y.X][cur.Y.Y] + 1;
			}


		}
	}

	int ans = -1;
	if (dist[0][N][M] == -1 && dist[1][N][M] == -1)
		cout << -1 << "\n";
	else {
		if (dist[0][N][M] != -1) ans = dist[0][N][M];
		if (dist[1][N][M] != -1)
			if (ans == -1) ans = dist[1][N][M];
			else		   ans = min(ans, dist[1][N][M]);
		cout << ans + 1 << "\n";
	}
	return 0;
}
