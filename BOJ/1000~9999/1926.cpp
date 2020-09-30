#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define X first
#define Y second
int paper[502][502];
bool check[502][502];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int> > q;
	int max = 0;
	int temp;
	int count = 0;
	int nx[4] = {-1, 1, 0, 0};
	int ny[4] = {0, 0, -1, 1};
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paper[i][j];
		}
	}

	for (int x = 0; x < n; x++) {
		for (int y = 0; y < m; y++) {
			if (paper[x][y] && !check[x][y]) {
				count++;
				temp = 1;
				q.push(pair<int, int>(x, y));
				check[x][y] = true;

				while (!q.empty()) {
					pair<int, int> cur = q.front();
					q.pop();

					for (int i = 0; i < 4; i++) {
						int tx = cur.X + nx[i];
						int ty = cur.Y + ny[i];

						if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
							if (paper[tx][ty] && !check[tx][ty]) {
								q.push(pair<int, int>(tx, ty));
								check[tx][ty] = true;
								temp++;
							}
						}
					}
				}

				if (temp > max) max = temp;
			}
		}
	}
	cout << count << "\n" << max << "\n";

	return 0;
}
