#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, num, find_num, result = 0;
	cin >> N;

	stack<int> s;

	for (int i = 0; i < N; i++) {
		cin >> num;
		s.push(num);
	}
	cin >> find_num;

	while (!s.empty()) {
		if (s.top() == find_num)
			result++;

		s.pop();
	}
	cout << result;
	return 0;
}
