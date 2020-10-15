#include <iostream>
#include <queue>
#include <algorithm>
#define X first
#define Y second
using namespace std;

int N, answer = 0;
int space[22][22];
int dist[22][22];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
pair<int, int> baby_pos;
int baby_size;
int eat = 0;

vector<pair<pair<int, int>, int> > BFS(int baby_x, int baby_y) {
	for (int x = 0; x < N; x++)
		fill(dist[x], dist[x] + N, -1);
	vector<pair<pair<int, int>, int> > target = {};
	queue<pair<int, int> > q;
	q.push({ baby_x, baby_y });
	dist[baby_x][baby_y] = 0;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx[i] + cur.X;
			int ny = dy[i] + cur.Y;

			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if (space[nx][ny] > baby_size || dist[nx][ny] != -1) continue;
			q.push({ nx, ny });
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			if (space[nx][ny] != 0 && space[nx][ny] < baby_size) target.push_back(make_pair(make_pair(nx, ny),dist[nx][ny]));
		}
	}
	return target;
}

bool compare(pair<pair<int, int>, int> A, pair<pair<int, int>, int> B) {
	if (A.Y == B.Y) {
		if (A.X.X == B.X.X) {
			return A.X.Y < B.X.Y;				
		}
		else {
			return A.X.X < B.X.X;
		}
	}
	else {
		return A.Y < B.Y;
	}
}

int solution() {
	while (1) {		
		vector<pair<pair<int, int>, int> > target = BFS(baby_pos.X, baby_pos.Y);
		int cnt = target.size();

		if (cnt == 0) {
			return 0;
		}
		else {
			if (cnt > 1) {
				sort(target.begin(), target.end(), compare);
			}
			answer += dist[target[0].X.X][target[0].X.Y];
			space[baby_pos.X][baby_pos.Y] = 0;
			baby_pos = target[0].X;
			space[target[0].X.X][target[0].X.Y] = 0;

			eat++;			
			if (baby_size == eat) {
				baby_size++;
				eat = 0;
			}
		}		
	}	
}

int main(void) {
	cin >> N;
	int input;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> input;
			space[x][y] = input;

			if (input == 9) {
				baby_pos.X = x;
				baby_pos.Y = y;
				baby_size = 2;
			}
		}
	}

	solution();
	cout << answer << "\n";
	return 0;
}