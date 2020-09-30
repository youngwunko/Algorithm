#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int iceberg[302][302];
int melt[302][302];
bool visited[302][302];
int N, M;
int tx[4] = { 0, 0, 1, -1 };
int ty[4] = { 1, -1, 0, 0 };

void bfs(int x, int y) {
	queue<pair<int, int> > q;
	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx + tx[i];
			int ny = dy + ty[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visited[nx][ny] && iceberg[nx][ny] > 0) {
					q.push({ nx, ny });
					visited[nx][ny] = 1;
				}
			}
		}
	}
}

int main(void){
	cin >> N >> M;
	int num;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> num;
			iceberg[x][y] = num;
		}
	}

	int year = 0;
	while (1) {
		memset(visited, 0, sizeof(visited));
		int cnt = 0;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (!visited[x][y] && iceberg[x][y] > 0) {
					bfs(x, y);
					cnt++;
				}
			}
		}
		if (cnt == 0) {
			cout << 0 << "\n";
			return 0;
		}
		if (cnt >= 2)
			break;

		memset(melt, 0, sizeof(melt));
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (iceberg[x][y] > 0) {
					for (int i = 0; i < 4; i++) {
						int nx = x + tx[i];
						int ny = y + ty[i];

						if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
							if (iceberg[nx][ny] == 0)
								melt[x][y]++;
						}
					}
				}
			}
		}
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				iceberg[x][y] -= melt[x][y];
				if (iceberg[x][y] < 0)
					iceberg[x][y] = 0;
			}
		}
		year++;
	}
	cout << year << "\n";
	return 0;
}
