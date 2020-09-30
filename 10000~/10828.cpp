#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int N, num;
	string cmd;
	cin >> N;

	while (N--) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
		else
		{
			if (cmd == "pop") {
				if (s.empty())
					cout << -1;
				else
				{
					cout << s.top();
					s.pop();
				}
			}
			else if (cmd == "size") {
				cout << s.size();
			}
			else if (cmd == "empty") {
				if (s.empty())
					cout << 1;
				else
					cout << 0;
			}
			else if (cmd == "top") {
				if (s.empty())
					cout << -1;
				else
					cout << s.top();
			}
			cout << "\n";
		}
	}
	return 0;
}
