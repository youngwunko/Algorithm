#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int color[102][102];
bool visited[102][102];
int N;

void bfs(int x, int y, int flag) {
	int tx[4] = { 0, 0, 1, -1 };
	int ty[4] = { 1, -1, 0, 0 };

	queue<pair<int, int> > q;
	q.push({ x, y });
	visited[x][y] = 1;
	int find_color = color[x][y];

	while (!q.empty()) {
		int dx = q.front().first;
		int dy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = dx + tx[i];
			int ny = dy + ty[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (!visited[nx][ny]) {
					// 적록색약이 아닐 때
					if (flag == 0) {
						if (find_color == color[nx][ny]) {
							q.push({ nx, ny });
							visited[nx][ny] = 1;
						}
					}
					// 적록색약일 때
					else {
						if (find_color != 2) {
							if (color[nx][ny] == 0 || color[nx][ny] == 1) {
								q.push({ nx, ny });
								visited[nx][ny] = 1;
							}
						}
						else if (find_color == color[nx][ny]) {
							q.push({ nx, ny });
							visited[nx][ny] = 1;
						}
					}
				}
			}
		}
	}
}

int main(void){
	cin >> N;
	cin.ignore();
	string input;
	for (int i = 0; i < N; i++) {
		// R -> 0 , G -> 1, B -> 2 로 변환해서 저장
		getline(cin, input);
		int length = input.size();
		for (int j = 0; j < length; j++) {
			if (input[j] == 'R')
				color[i][j] = 0;
			else if (input[j] == 'G')
				color[i][j] = 1;
			else if (input[j] == 'B')
				color[i][j] = 2;
		}
	}

	int result = 0;
	// 적록색약이 아닌 사람
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (!visited[x][y]) {
				result++;
				bfs(x, y, 0);
			}
		}
	}
	cout << result << " ";

	memset(visited, 0, sizeof(visited));
	result = 0;
	// 적록색약인 사람
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (!visited[x][y]) {
				result++;
				bfs(x, y, 1);
			}
		}
	}
	cout << result << "\n";

	return 0;
}
