#include <iostream>
#include <queue>
#include <vector>

#define X first
#define Y second
#define MAX 200
using namespace std;

int K, W, H;
int board[MAX + 2][MAX + 2];
int method[32][MAX + 2][MAX + 2];
int dx[12] = { 0, 0, 1, -1,  2,  1, -1, -2, 2, 1, -1, -2 };
int dy[12] = { 1, -1, 0, 0, -1, -2, -2, -1, 1, 2,  2,  1 };

int main(void) {
	cin >> K >> W >> H;
	int num;
	for (int x = 0; x < H; x++) {
		for (int y = 0; y < W; y++) {
			cin >> num;
			board[x][y] = num;
		}
	}

	queue<pair<int, pair<int, int> > > q;
	q.push({ 0, {0, 0} });
	method[0][0][0] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 12; i++) {
			if (cur.X == K && i >= 4) continue;
			int nk = (i < 4) ? cur.X : cur.X + 1;
			int nx = cur.Y.X + dx[i];
			int ny = cur.Y.Y + dy[i];

			if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
			if (board[nx][ny] == 1) continue;
			if (method[nk][nx][ny] == 0 || method[nk][nx][ny] > method[cur.X][cur.Y.X][cur.Y.Y] + 1) {
				method[nk][nx][ny] = method[cur.X][cur.Y.X][cur.Y.Y] + 1;
				q.push({ nk, { nx, ny } });
			}
		}
	}
	int ans = MAX * MAX;
	for (int i = 0; i <= K; i++) {
		if (method[i][H - 1][W - 1] > 0)
			ans = min(ans, method[i][H - 1][W - 1]);
	}
	if (ans == MAX * MAX)
		cout << -1 << "\n";
	else
		cout << ans - 1 << "\n";
	return 0;
}
