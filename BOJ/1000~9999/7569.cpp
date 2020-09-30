#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define MAX 100
int visited[MAX + 2][MAX + 2][MAX + 2];
int tomato[MAX + 2][MAX + 2][MAX + 2];
int M, N, H;

int main(void) {
	int nh[6] = { 1, -1, 0, 0, 0, 0 };
	int nx[6] = {0, 0, 0, 0, 1, -1 };
	int ny[6] = {0, 0, 1, -1, 0, 0 };
	queue<pair<int, pair<int, int> > > q;
	cin >> M >> N >> H;
	int num;

	for (int h = 0; h < H; h++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				cin >> num;
				tomato[h][x][y] = num;
				if (num == -1)
					visited[h][x][y] = -1;
				else if (num == 1) {
					q.push(make_pair(h, make_pair(x, y)));
					visited[h][x][y] = 1;
				}
			}
		}
	}

	while (!q.empty()) {
		int dh = q.front().first;
		int dx = q.front().second.first;
		int dy = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int th = dh + nh[i];
			int tx = dx + nx[i];
			int ty = dy + ny[i];

			if (th >= 0 && th < H && tx >= 0 && tx < N && ty >= 0 && ty < M) {
				if (visited[th][tx][ty] == 0 && tomato[th][tx][ty] == 0) {
					visited[th][tx][ty] = visited[dh][dx][dy] + 1;
					q.push(make_pair(th, make_pair(tx, ty)));
				}
			}
		}
	}

	int result = 0;
	for (int h = 0; h < H; h++) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < M; y++) {
				if (visited[h][x][y] == 0) { // 모두 익지 않은 상황
					cout << -1 << "\n";
					return 0;
				}
				else {
					if (visited[h][x][y] > result)
						result = visited[h][x][y];
				}
			}
		}
	}
	cout << result - 1 << "\n";

	return 0;
}
