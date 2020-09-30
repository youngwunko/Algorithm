#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[102][102];
int land[102][102];
int length[102][102];

int tx[4] = { 0, 0, 1, -1 };
int ty[4] = { 1, -1, 0, 0 };
int N, cnt = 0;

void find_land(int x, int y, int cnt) {
	queue<pair<int, int> > q;
	q.push({ x, y });
	land[x][y] = cnt;

	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx + tx[i];
			int ny = dy + ty[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (map[nx][ny] && !land[nx][ny]) {
					q.push({ nx, ny });
					land[nx][ny] = cnt;
				}
			}
		}
	}
}

void calc_dist(int x, int y, int find_land) {
	queue<pair<int, int> > q;
	q.push({ x, y });
	length[x][y] = 1;

	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx + tx[i];
			int ny = dy + ty[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (land[nx][ny] != find_land){
					if (length[nx][ny] == 0 || length[nx][ny] > length[dx][dy] + 1) {
						q.push({ nx, ny });
						length[nx][ny] = length[dx][dy] + 1;
					}
				}
			}
		}
	}
}

int main(void){
	cin >> N;
	int num;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> num;
			map[x][y] = num;
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (map[x][y] && !land[x][y]) {
				cnt++;
				find_land(x, y, cnt);
			}
		}
	}

	int result = 987654321;
	for (int m = 1; m <= cnt; m++) {
		memset(length, 0, sizeof(length));

		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (land[x][y] == m)
					calc_dist(x, y, m);
			}
		}

		int min = 987654321;
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (land[x][y] != 0 && land[x][y] != m && length[x][y] < min)
					min = length[x][y];
			}
		}
		if (result > min)
			result = min;
	}
	cout << result - 2 << "\n";
	return 0;
}
