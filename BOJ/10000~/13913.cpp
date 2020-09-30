#include <iostream>
#include <queue>
#include <stack>
using namespace std;

pair<int, int> find_time[100003];

int main(void){
	int N, K;
	cin >> N >> K;

	queue<int> q;
	q.push(N);
	find_time[N] = { N, 1 };
	int nx[3];

	while (!q.empty()) {
		int dx = q.front();
		q.pop();

		nx[0] = dx * 2;
		nx[1] = dx + 1;
		nx[2] = dx - 1;

		for (int i = 0; i < 3; i++) {
			if (nx[i] >= 0 && nx[i] <= 100000) {
				if (find_time[nx[i]].second == 0 || find_time[nx[i]].second > find_time[dx].second + 1) {
					find_time[nx[i]].first = dx;
					find_time[nx[i]].second = find_time[dx].second + 1;
					q.push(nx[i]);
				}
			}
		}
	}
	cout << find_time[K].second - 1 << "\n";
	stack<int> s;
	s.push(K);
	int pos = K;
	while (1) {
		pos = find_time[pos].first;
		if (pos == N)
			break;
		else
			s.push(pos);
	}
	if(N != K)
		s.push(pos);

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";

	return 0;
}
