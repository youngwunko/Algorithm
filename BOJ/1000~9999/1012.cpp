#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;
bool cabbage[52][52];
bool check[52][52];
int M, N, K;

void bfs(int x, int y) {
	int nx[4] = { 0, 0, 1, -1 };
	int ny[4] = { 1, -1, 0, 0 };

	queue<pair<int, int> > s;

	check[x][y] = true;
	s.push({ x, y });
	while (!s.empty()) {
		int tx = s.front().first;
		int ty = s.front().second;
		s.pop();

		for (int i = 0; i < 4; i++) {
			int dx = tx + nx[i];
			int dy = ty + ny[i];

			if (dx >= 0 && dy >= 0 && dx < M && dy < N) {
				if (!check[dx][dy] && cabbage[dx][dy]) {
					s.push({ dx, dy });
					check[dx][dy] = true;
				}
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;
	while (T--) {
		cin >> M >> N >> K;
		fill(&cabbage[0][0], &cabbage[51][52], 0);
		fill(&check[0][0], &check[51][52], 0);

		int X, Y, cnt = 0;
		while (K--) {
			cin >> X >> Y;
			cabbage[X][Y] = true;
		}

		for (int x = 0; x < M; x++) {
			for (int y = 0; y < N; y++) {
				if (!check[x][y] && cabbage[x][y]) {
					bfs(x, y);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
