#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool area[102][102];
bool visited[102][102];
int M, N, K;

int bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int, int> > q;
	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int tx = q.front().first;
		int ty = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = tx + dx[i];
			int ny = ty + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (!visited[nx][ny] && !area[nx][ny]) {
					q.push({ nx, ny });
					visited[nx][ny] = 1;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main(void){
	cin >> M >> N >> K;
	vector<int> v;

	int x1, y1, x2, y2;
	for (int i = 0; i < K; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int x = x1; x < x2; x++) {
			for (int y = y1; y < y2; y++)
				area[x][y] = 1;
		}
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < M; y++) {
			if (!visited[x][y] && !area[x][y])
				v.push_back(bfs(x, y));
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto i : v)
		cout << i << " ";
	return 0;
}
