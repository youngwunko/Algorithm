#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, dis;
vector<int> connect[102];
bool visited[102];

int main(void) {
	cin >> N >> dis;

	int com1, com2;
	while (dis--) {
		cin >> com1 >> com2;
		connect[com1].push_back(com2);
		connect[com2].push_back(com1);
	}

	int virus = 0;
	queue<int> q;
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (auto i : connect[cur]) {
			if (visited[i]) continue;
			q.push(i);
			visited[i] = 1;
			virus++;
		}
	}
	cout << virus << "\n";
	return 0;
}
