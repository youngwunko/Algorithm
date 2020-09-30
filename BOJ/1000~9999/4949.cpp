#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1) {
		string s;
		bool flag = 0;
		stack<char> stk;
		getline(cin, s);

		if (s != ".") {
			for (char i : s) {
				if (i == '(' || i == '[') {
					stk.push(i);
				}
				else if (i == ')') {
					if (stk.empty()) {
						flag = 1;
						break;
					}
					else {
						if (stk.top() == '(') {
							stk.pop();
						}
						else {
							flag = 1;
							break;
						}
					}
				}
				else if (i == ']') {
					if (stk.empty()) {
						flag = 1;
						break;
					}
					else {
						if (stk.top() == '[') {
							stk.pop();
						}
						else {
							flag = 1;
							break;
						}
					}
				}
			}
			if (flag == 1) {
				cout << "no\n";
			}
			else {
				if (stk.empty()) {
					cout << "yes\n";
				}
				else {
					cout << "no\n";
				}
			}
		}
		else
			break;
	}
	return 0;
}
