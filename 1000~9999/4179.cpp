#include <iostream>
#include <queue>
#include <utility>
#include <string>

#define X first
#define Y second

using namespace std;

int maze[1002][1002];
int fire[1002][1002];
int jihoon[1002][1002];
int R, C;

int main(void) {
	queue<pair<int, int> > fq;
	queue<pair<int, int> > jhq;

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		fill(maze[i], maze[i] + C, -1);
	}

	string input;
	for (int x = 0; x < R; x++) {
		cin >> input;
		for (int y = 0; y < C; y++) {
			if (input[y] == 'F') {
				fq.push({ x, y });
				fire[x][y];
			}
			else if (input[y] == 'J') {
				jhq.push({ x, y });
				jihoon[x][y];
				maze[x][y] = 0;
			}
			else if (input[y] == '.') {
				maze[x][y] = 0;
			}
		}
	}

	int nx[4] = { 0, 0, 1, -1 };
	int ny[4] = { 1, -1, 0, 0 };

	while (!fq.empty()) {
		int dx = fq.front().X;
		int dy = fq.front().Y;
		fq.pop();

		for (int i = 0; i < 4; i++) {
			int tx = dx + nx[i];
			int ty = dy + ny[i];

			if (tx < 0 || ty < 0 || tx >= R || ty >= C) continue;
			if (maze[tx][ty] == -1 || fire[tx][ty]) continue;
			fq.push({ tx, ty });
			fire[tx][ty] = fire[dx][dy] + 1;
		}
	}

	while (!jhq.empty()) {
		int dx = jhq.front().X;
		int dy = jhq.front().Y;
		jhq.pop();

		for (int i = 0; i < 4; i++) {
			int tx = dx + nx[i];
			int ty = dy + ny[i];

			if (tx < 0 || ty < 0 || tx >= R || ty >= C) {
				cout << jihoon[dx][dy] + 1 << "\n";
				return 0;
			}
			if (maze[tx][ty] == -1 || jihoon[tx][ty]) continue;
			if (fire[tx][ty] && fire[tx][ty] <= jihoon[dx][dy] + 1) continue;

			jhq.push({ tx, ty });
			jihoon[tx][ty] = jihoon[dx][dy] + 1;
		}
	}
	cout << "IMPOSSIBLE\n";
	return 0;
}
