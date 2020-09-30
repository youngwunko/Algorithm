#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int N; cin >> N;
	long long result = 0;
	int height;

	while (N--) {
		cin >> height;
		if (s.empty())
			s.push(height);
		else {
			if (height >= s.top()) {
				do {
					s.pop();
					if (s.empty())
						break;
				} while (s.top() <= height);
			}
			result += s.size();
			s.push(height);
		}
	}
	cout << result;
	return 0;
}
