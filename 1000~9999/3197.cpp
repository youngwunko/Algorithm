#include <iostream>
#include <queue>
#include <string>

#define X first
#define Y second
using namespace std;

char lake[1502][1502];
int days[1502][1502];
bool visit[1502][1502];

int R, C;
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector<pair<int, int> > duck;

bool duck_meet(int mid) {
	for (int x = 0; x < R; x++)
		fill(visit[x], visit[x] + C, 0);

	queue<pair<int, int> > q;
	q.push(duck[0]);
	visit[duck[0].X][duck[0].Y] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (visit[nx][ny] || days[nx][ny] > mid) continue;
			if (nx == duck[1].X && ny == duck[1].Y) {
				return true;
			}
			q.push({ nx, ny });
			visit[nx][ny] = 1;
		}
	}
	return false;
}

int main(void) {
	cin >> R >> C;
	string input;
	queue<pair<int, int> > q;
	for (int x = 0; x < R; x++)
		fill(days[x], days[x] + C, -1);

	for (int x = 0; x < R; x++) {
		cin >> input;
		for (int y = 0; y < C; y++) {
			lake[x][y] = input[y];
			if (input[y] == 'L') {
				duck.push_back({ x, y });
				lake[x][y] = '.';
			}
			if (lake[x][y] == '.') {
				q.push({ x, y });
				days[x][y] = 0;

			}
		}
	}

	int max_day = 0;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (lake[nx][ny] == '.' || days[nx][ny] >= 0) continue;
			q.push({ nx, ny });
			days[nx][ny] = days[cur.X][cur.Y] + 1;
			max_day = max(max_day, days[nx][ny]);
		}
	}

	int s = 0, e = max_day, ans = 987456321;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (duck_meet(mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
