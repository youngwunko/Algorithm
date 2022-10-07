#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int N, K;
	queue<int> Q;

	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		Q.push(i);
	}

	int num;
	cout << "<";
	while (N) {
		if (N == 1) {
			cout << Q.front() << ">";
			break;
		}

		for (int i = 1; i < K; i++) {
			num = Q.front();
			Q.pop();
			Q.push(num);
		}
		cout << Q.front() << ", ";
		Q.pop();
		N--;
	}
	return 0;
}