#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int apt[27][27];
bool visited[27][27];
int N;

int bfs(int x, int y) {
	int cnt = 1;
	queue<pair<int,int> > q;
	int nx[4] = { 0, 0, 1, -1 };
	int ny[4] = { 1, -1, 0, 0 };

	q.push({ x, y });
	visited[x][y] = 1;

	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int tx = dx + nx[i];
			int ty = dy + ny[i];

			if (tx >= 0 && tx < N && ty >= 0 && ty < N) {
				if (!visited[tx][ty] && apt[tx][ty]) {
					q.push({ tx, ty });
					visited[tx][ty] = 1;
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int main(void) {
	cin >> N;
	cin.ignore();
	vector<int> v;
	string input;

	for (int i = 0; i < N; i++) {
		getline(cin, input);
		for (int j = 0; j < N; j++)
			(input[j] == '0') ? (apt[i][j] = 0) : (apt[i][j] = 1);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && apt[i][j])
				v.push_back(bfs(i, j));
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (auto i : v) {
		cout << i << "\n";
	}

	return 0;
}
