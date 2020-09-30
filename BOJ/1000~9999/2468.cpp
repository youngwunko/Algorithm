#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int rain[102][102];
bool visited[102][102];
int N;

void bfs(int x, int y, int h) {
	queue<pair<int, int> > q;
	int tx[4] = { 0, 0, 1, -1 };
	int ty[4] = { 1, -1, 0, 0 };

	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx + tx[i];
			int ny = dy + ty[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (!visited[nx][ny] && rain[nx][ny] > h) {
					q.push({ nx, ny });
					visited[nx][ny] = 1;
				}
			}
		}
	}
}

int main(void){
	cin >> N;
	int num;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			rain[i][j] = num;
		}
	}

	int max = 0;
	for (int h = 0; h <= 100; h++) {
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (!visited[x][y] && rain[x][y] > h) {
					bfs(x, y, h);
					cnt++;
				}
			}
		}
		if (cnt > max)
			max = cnt;
		if (cnt == 0)
			break;
	}
	cout << max << "\n";
	return 0;
}
