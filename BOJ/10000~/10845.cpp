#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int N, num;
	string cmd;
	cin >> N;

	while (N--) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> num;
			q.push(num);
		}
		else
		{
			if (cmd == "pop") {
				if (q.empty())
					cout << -1;
				else
				{
					cout << q.front();
					q.pop();
				}
			}
			else if (cmd == "size") {
				cout << q.size();
			}
			else if (cmd == "empty") {
				if (q.empty())
					cout << 1;
				else
					cout << 0;
			}
			else if (cmd == "front") {
				if (q.empty())
					cout << -1;
				else
					cout << q.front();
			}
			else if (cmd == "back") {
				if (q.empty())
					cout << -1;
				else
					cout << q.back();
			}
			cout << "\n";
		}
	}
	return 0;
}
