#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;

	int K; cin >> K;
	int num;

	while (K--) {
		cin >> num;
		if (num == 0)
			s.pop();
		else
			s.push(num);
	}

	int total = 0;
	while (!s.empty()) {
		total += s.top();
		s.pop();
	}
	cout << total;

	return 0;
}
