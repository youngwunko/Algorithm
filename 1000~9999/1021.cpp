#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int N, M; cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		dq.push_back(i);
	}

	int cnt = 0;
	int find;
	while (M--) {
		cin >> find;

		if (find == dq.front())
			dq.pop_front();
		else {
			int temp1 = 0, temp2 = 0;
			while (find != dq[temp1])
				temp1++;
			while (find != dq[dq.size() - temp2 - 1])
				temp2++;
			temp2++;

			if (temp1 < temp2) {
				while (find != dq.front()) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
				cnt += temp1;
			}
			else {
				while (find != dq.front()) {
					dq.push_front(dq.back());
					dq.pop_back();
				}
				cnt += temp2;
			}
			dq.pop_front();
		}
	}
	cout << cnt << "\n";
	return 0;
}
