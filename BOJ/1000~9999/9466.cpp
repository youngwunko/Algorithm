#include <iostream>
#include <queue>

using namespace std;

int team[100002];
bool visit[100002];

int main(void) {
	int T; cin >> T;
	for (int i = 0; i < T; i++) {
		int n; cin >> n;
		fill(team, team + n + 2, 0);
		fill(visit, visit + n + 2, 0);
		int success = 0, num;
		for (int x = 1; x <= n; x++) {
			cin >> num;
			team[x] = num;
		}

		for (int x = 1; x <= n; x++) {
			if (visit[x]) continue;
			queue<int> q;
			q.push(x);
			visit[x] = 1;

			while (!visit[team[q.back()]]) {
				visit[team[q.back()]] = 1;
				q.push(team[q.back()]);
			}

			int start = team[q.back()];
			while (!q.empty() && q.front() != start) {
				q.pop();
			}
			success += q.size();
		}
		cout << n - success << "\n";
	}
	return 0;
}
