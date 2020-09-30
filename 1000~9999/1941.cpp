#include <iostream>
#include <string>
#include <queue>
using namespace std;

char room[5][5];
bool isused[5][5];
bool bfs_visit[5][5];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int ans = 0, y_num = 0;

void select_team(int k, int next) {
	if (k == 7) {
		// 인접했는지 확인
		for (int i = 0; i < 5; i++)
			fill(bfs_visit[i], bfs_visit[i] + 5, 0);

		queue<pair<int, int> > q;
		q.push({ (next - 1) / 5, (next - 1) % 5 });
		bfs_visit[(next - 1) / 5][(next - 1) % 5] = 1;
		int cnt = 1;

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];

				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
				if (!isused[nx][ny] || bfs_visit[nx][ny]) continue;
				q.push({ nx, ny });
				bfs_visit[nx][ny] = 1;
				cnt++;
			}
		}

		if(cnt == 7) ans++;
		return;
	}

	for (int i = next; i < 25; i++) {
		if (isused[i / 5][i % 5]) continue;
		if (room[i / 5][i % 5] == 'Y') {
			if (y_num == 3) continue;
			y_num++;
		}

		isused[i / 5][i % 5] = 1;
		select_team(k + 1, i + 1);
		if (room[i / 5][i % 5] == 'Y') y_num--;
		isused[i / 5][i % 5] = 0;
	}
}

int main(void) {
	string input;
	for (int x = 0; x < 5; x++) {
		cin >> input;
		for (int y = 0; y < 5; y++)
			room[x][y] = input[y];
	}

	select_team(0, 0);

	cout << ans << "\n";
	return 0;
}
