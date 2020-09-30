#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int visited[302][302];
int N;

int bfs(int x, int y, int rx, int ry) {
	queue<pair<int, int> > q;
	int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
	int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

	if (x == rx && y == ry)
		return 0;
	q.push({ x, y });

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (!visited[nx][ny]) {
					q.push({ nx, ny });
					visited[nx][ny] = visited[tx][ty] + 1;

					if (nx == rx && ny == ry)
						return visited[nx][ny];
				}
			}
		}
	}
}

int main(void){
	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		memset(visited, 0, sizeof(visited));
		cin >> N;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << bfs(x1, y1, x2, y2) << "\n";
	}
	return 0;
}
