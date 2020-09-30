#include <iostream>
#include <queue>
#include <utility>

#define X first
#define Y second
using namespace std;

bool light_on[102][102];
bool visit[102][102];
vector<pair<int, int> > turn_on[102][102];
int N, M;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int main(void) {
	int max_light = 1;
	cin >> N >> M;

	int x, y, a, b;
	for (int i = 0; i < M; i++) {
		cin >> x >> y >> a >> b;
		turn_on[x][y].push_back({ a, b });
	}

	queue<pair<int, int> > q;
	q.push({ 1, 1 });
	light_on[1][1] = 1;
	visit[1][1] = 1;

	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		for (pair<int, int> turn : turn_on[cur.X][cur.Y]) {
			if (!light_on[turn.X][turn.Y]) {
				light_on[turn.X][turn.Y] = 1;
				max_light++;

				for (int i = 0; i < 4; i++) {
					int tx = turn.X + dx[i];
					int ty = turn.Y + dy[i];
					if (tx < 1 || tx > N || ty < 1 || ty > N) continue;
					if (light_on[tx][ty] && visit[tx][ty]) {
						q.push({ turn.X, turn.Y });
						visit[turn.X][turn.Y] = 1;
						break;
					}
				}
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];

			if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
			if (!light_on[nx][ny] || visit[nx][ny]) continue;
			q.push({ nx, ny });
			visit[nx][ny] = 1;
		}
	}

	cout << max_light << "\n";
	return 0;
}
