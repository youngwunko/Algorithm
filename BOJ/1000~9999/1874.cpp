#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	vector<char> result;
	bool flag = 0;

	int N; cin >> N;
	int num, now = 1;

	while (N--) {
		cin >> num;
		if (s.empty()) {
			s.push(now);
			now++;
			result.push_back('+');
		}
		if (num > s.top()) {
			while (num - s.top()) {
				s.push(now);
				now++;
				result.push_back('+');
			}

		}
		else if (num < s.top()) {
			flag = 1;
			break;
		}
		s.pop();
		result.push_back('-');
	}
	if (flag == 1)
		cout << "NO\n";
	else {
		for (auto i : result)
			cout << i << "\n";
	}

	return 0;
}
