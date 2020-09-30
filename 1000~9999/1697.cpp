#include <iostream>
#include <queue>

using namespace std;
#define MAX 100000
int visited[MAX+2];

int main(void) {
	int N, K; cin >> N >> K;

	queue<int> q;
	visited[N] = 1;
	q.push(N);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (now == K)
			break;

		if (now + 1 <= MAX && !visited[now + 1]) {
			q.push(now + 1);
			visited[now + 1] = visited[now] + 1;
		}

		if (now - 1 >= 0 && !visited[now - 1]) {
			q.push(now - 1);
			visited[now - 1] = visited[now] + 1;
		}

		if (now * 2 <= MAX && !visited[now * 2]) {
			q.push(now * 2);
			visited[now * 2] = visited[now] + 1;
		}
	}
	cout << visited[K] - 1 << "\n";

	return 0;
}
