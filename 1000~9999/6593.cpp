#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int th[6] = { 1, -1, 0, 0, 0, 0 };
int tx[6] = { 0, 0, 0, 0, 1, -1 };
int ty[6] = { 0, 0, 1, -1, 0, 0 };
int L, R, C;

char building[32][32][32];
int esc_time[32][32][32];

void bfs(int h, int x, int y) {
	queue<pair<int, pair<int, int> > > q;
	q.push({ h, { x, y } });
	esc_time[h][x][y] = 1;

	while (!q.empty()) {
		int dh = q.front().first;
		int dx = q.front().second.first;
		int dy = q.front().second.second;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = dh + th[i];
			int nx = dx + tx[i];
			int ny = dy + ty[i];

			if (nh >= 0 && nh < L && nx >= 0 && nx < R && ny >= 0 && ny < C) {
				if (building[nh][nx][ny] != '#' && !esc_time[nh][nx][ny]) {
					q.push({ nh, {nx, ny} });
					esc_time[nh][nx][ny] = esc_time[dh][dx][dy] + 1;
				}
			}
		}
	}
}

int main(void){
	while (1) {
		memset(esc_time, 0, sizeof(esc_time));
		cin >> L >> R >> C;
		cin.ignore();
		if ((L + R + C) == 0)
			break;

		int now_x, now_y, now_h, exit_x, exit_y, exit_h;
		string input;
		for (int h = 0; h < L; h++) {
			for (int x = 0; x < R; x++) {
				getline(cin, input);
				for (int y = 0; y < C; y++) {
					if (input[y] == 'S') {
						now_h = h;
						now_x = x;
						now_y = y;
					}
					else if (input[y] == 'E') {
						exit_h = h;
						exit_x = x;
						exit_y = y;
					}
					building[h][x][y] = input[y];
				}
			}
			cin.ignore();
		}

		bfs(now_h, now_x, now_y);

		if (esc_time[exit_h][exit_x][exit_y] == 0)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << esc_time[exit_h][exit_x][exit_y] - 1 << " minute(s).\n";
	}
	return 0;
}
