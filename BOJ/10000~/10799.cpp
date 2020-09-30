#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int total = 0;
	bool flag = 0;
	stack<char> s;

	string input;
	cin >> input;

	for (char a : input) {
		if (a == '(') {
			total++;
			s.push(a);
			flag = 1;
		}
		else {
			if (flag == 1) {
				total += s.size() - 2;
			}
			s.pop();
			flag = 0;
		}
	}
	cout << total;
	return 0;
}
