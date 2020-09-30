#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

int N, M, V;
set<int> connect[1002];
bool visited[1002];

int main(void) {
	cin >> N >> M >> V;

	int v1, v2;
	while (M--) {
		cin >> v1 >> v2;

		connect[v1].insert(v2);
		connect[v2].insert(v1);
	}

	// DFS
	stack<int> s;
	s.push(V);
	visited[V] = 1;
	cout << V << " ";

	while (!s.empty()) {
		int cur = s.top();
		bool flag = 0;

		for (int i : connect[cur]) {
			if (!visited[i]) {
				s.push(i);
				visited[i] = 1;
				cout << i << " ";
				flag = 1;
				break;
			}
		}
		if(flag == 0) s.pop();
	}
	cout << "\n";

	fill(visited, visited + 1002, 0);
	// BFS
	queue<int> q;
	q.push(V);
	visited[V] = 1;
	cout << V << " ";

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i : connect[cur]) {
			if (visited[i]) continue;
			q.push(i);
			visited[i] = 1;
			cout << i << " ";
		}
	}
	cout << "\n";

	return 0;
}
