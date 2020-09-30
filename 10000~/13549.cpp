#include <iostream>
#include <queue>
using namespace std;

int find_time[100003];

int main(void){
	int N, K;
	cin >> N >> K;

	queue<int> q;
	q.push(N);
	find_time[N] = 1;
	int nx[3];

	while (!q.empty()) {
		int dx = q.front();
		q.pop();

		nx[0] = dx * 2;
		nx[1] = dx + 1;
		nx[2] = dx - 1;

		for (int i = 0; i < 3; i++) {
			if (nx[i] >= 0 && nx[i] <= 100000) {
				if (find_time[nx[i]] == 0 || find_time[nx[i]] > find_time[dx] + 1) {
					if (i != 0)
						find_time[nx[i]] = find_time[dx] + 1;
					else
						find_time[nx[i]] = find_time[dx];
					q.push(nx[i]);
				}
			}
		}
	}
	cout << find_time[K] - 1 << "\n";
	return 0;
}
