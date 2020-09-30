#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int N, num;
	string cmd;
	cin >> N;

	while (N--) {
		cin >> cmd;

		if (cmd == "push_front") {
			cin >> num;
			dq.push_front(num);
		}
		else if (cmd == "push_back")
		{
			cin >> num;
			dq.push_back(num);
		}
		else
		{
			if (cmd == "pop_front") {
				if (dq.empty())
					cout << -1;
				else
				{
					cout << dq.front();
					dq.pop_front();
				}
			}
			if (cmd == "pop_back") {
				if (dq.empty())
					cout << -1;
				else
				{
					cout << dq.back();
					dq.pop_back();
				}
			}
			else if (cmd == "size") {
				cout << dq.size();
			}
			else if (cmd == "empty") {
				if (dq.empty())
					cout << 1;
				else
					cout << 0;
			}
			else if (cmd == "front") {
				if (dq.empty())
					cout << -1;
				else
					cout << dq.front();
			}
			else if (cmd == "back") {
				if (dq.empty())
					cout << -1;
				else
					cout << dq.back();
			}
			cout << "\n";
		}
	}
	return 0;
}
