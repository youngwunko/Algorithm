#include <iostream>
#include <queue>

#define MAX 500000
#define X first
#define Y second
using namespace std;

int subin[2][MAX + 2];

int N, K;
int main(void) {
	cin >> N >> K;

	fill(subin[0], subin[0] + MAX + 2, -1);
	fill(subin[1], subin[1] + MAX + 2, -1);
	queue<pair<int, int> > q1;
	q1.push({ 0, N });
	subin[0][N] = 0;
	while (!q1.empty()) {
		auto cur = q1.front(); q1.pop();

		for (int next : {cur.Y - 1, cur.Y + 1, cur.Y * 2}) {
			if (next < 0 || next > MAX) continue;
			if (subin[(cur.X + 1) % 2][next] != -1) continue;
			q1.push({(cur.X + 1) % 2 , next});
			subin[(cur.X + 1) % 2][next] = subin[cur.X][cur.Y] + 1;
		}
	}

	int i = 0, ans = MAX + 10;
	while (1) {
		K += i;
		if (K > MAX) break;
		if (subin[i % 2][K] <= i) ans = min(ans, i);
		i++;
	}
	if(ans == MAX + 10)	cout << -1 << "\n";
	else cout << ans << "\n";
	return 0;
}
