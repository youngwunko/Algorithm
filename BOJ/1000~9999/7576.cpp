#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define MAX 1000
int visited[MAX + 2][MAX + 2];
int tomato[MAX + 2][MAX + 2];
int M, N;

int main(void) {
	int nx[4] = { 0, 0, 1, -1 };
	int ny[4] = { 1, -1, 0, 0 };
	queue<pair<int, int> > q;
	cin >> M >> N;
	int num;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			cin >> num;
			tomato[x][y] = num;
			if (num == -1)
				visited[x][y] = -1;
			else if (num == 1) {
				q.push({ x, y });
				visited[x][y] = 1;
			}
		}
	}

	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = dx + nx[i];
			int ty = dy + ny[i];

			if (tx >= 0 && tx < N && ty >= 0 && ty < M) {
				if (visited[tx][ty] == 0 && tomato[tx][ty] == 0) {
					visited[tx][ty] = visited[dx][dy] + 1;
					q.push({ tx, ty });
				}
			}
		}
	}

	int result = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (tomato[x][y] == -1) continue;
			if (visited[x][y] == 0) { // 모두 익지 않은 상황
				result = -1;
				break;
			}
			else {
				if (visited[x][y] > result)
					result = visited[x][y];
			}
		}
		if (result == -1)
			break;
	}
	if (result == -1) // 모두 익지는 못하는 상황
		cout << -1 << "\n";
	else if (result == 0) // 모두 익어 있는 상황
		cout << 0 << "\n";
	else
		cout << result - 1 << "\n";
	return 0;
}
