#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

char state[1002][1002];
int escape_time[1002][1002];
int fire_time[1002][1002];
int W, H;
int tx[4] = { 0, 0, 1, -1 };
int ty[4] = { 1, -1, 0, 0 };
queue<pair<int, int> > fire;

void bfs(int x, int y, int flag) {
	if (flag == 0) {
		while (!fire.empty()) {
			int dx = fire.front().first;
			int dy = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int nx = dx + tx[i];
				int ny = dy + ty[i];

				if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
					if (!fire_time[nx][ny] && (state[nx][ny] == '.' || state[nx][ny] == '@')) {
						fire.push({ nx, ny });
						fire_time[nx][ny] = fire_time[dx][dy] + 1;
					}
				}
			}
		}
	}
	else {
		queue<pair<int, int> > q;
		q.push({ x, y });
		escape_time[x][y] = 1;

		while (!q.empty()) {
			int dx = q.front().first;
			int dy = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = dx + tx[i];
				int ny = dy + ty[i];

				if (nx >= 0 && nx < H && ny >= 0 && ny < W) {
					if (!escape_time[nx][ny] && state[nx][ny] == '.') {
						q.push({ nx, ny });
						escape_time[nx][ny] = escape_time[dx][dy] + 1;
					}
				}
			}
		}
	}
}

int main(void){
	int T; cin >> T;

	for (int i = 0; i < T; i++) {
		memset(fire_time, 0, sizeof(fire_time));
		memset(escape_time, 0, sizeof(escape_time));
		cin >> W >> H;
		cin.ignore();
		int time = 0;
		int now_x, now_y;

		string input;
		for (int x = 0; x < H; x++) {
			getline(cin, input);
			for (int y = 0; y < W; y++) {
				state[x][y] = input[y];
				if (input[y] == '@') {
					now_x = x;
					now_y = y;
				}
				if (input[y] == '*') {
					fire.push({ x, y });
					fire_time[x][y] = 1;
				}
			}
		}

		if(!fire.empty())
			bfs(fire.front().first, fire.front().second, 0);
		bfs(now_x, now_y, 1);

		int fast_time = 987654321;
		for (int x = 0; x < H; x++) {
			for (int y = 0; y < W; y++) {
				if (x == 0 || x == (H - 1) || y == 0 || y == (W - 1)) {
					if (escape_time[x][y] > 0) {
						if (escape_time[x][y] < fire_time[x][y] || fire_time[x][y] == 0)
							if (escape_time[x][y] < fast_time)
								fast_time = escape_time[x][y];
					}
				}
			}
		}
		if (fast_time == 987654321)
			cout << "IMPOSSIBLE\n";
		else
			cout << fast_time << "\n";
	}
	return 0;
}
