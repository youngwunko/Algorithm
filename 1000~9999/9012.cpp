#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
	int N; cin >> N;

	while (N--) {
		string input; cin >> input;
		stack<char> s;
		bool flag = false;

		for (auto i : input) {
			if (i == '(') {
				s.push(i);
			}
			else {
				if (s.empty()) {
					flag = true;
					break;
				}
				else {
					if (s.top() == '(')
						s.pop();
					else {
						flag = true;
						break;
					}
				}
			}
		}
		if (flag == false && s.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
