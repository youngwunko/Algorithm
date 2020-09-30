#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int test_case = 0;

	while (1) {
		string input; cin >> input;
		stack<char> s;
		int cnt = 0;

		if (input[0] == '-')
			break;
		else {
			test_case++;

			for (auto i : input) {
				if (i == '{')
					s.push(i);
				else {
					if (s.empty()) {
						s.push('{');
						cnt++;
					}
					else {
						if (s.top() == '{')
							s.pop();
					}
				}
			}
			cnt += (int)s.size() / 2;

			cout << test_case << ". " << cnt << "\n";
		}
	}

	return 0;
}
