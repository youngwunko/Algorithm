#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;

	while (T--) {
		list<char> password = {};
		string input;
		cin >> input;

		list<char>::iterator it;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '<') {
				if (!password.empty()) {
					if (it != password.begin())
						it--;
				}
			}
			else if (input[i] == '>') {
				if (!password.empty()) {
					if (it != password.end())
						it++;
				}
			}
			else if (input[i] == '-') {
				if (!password.empty()) {
					if (it != password.begin())
						it = password.erase(--it);
				}
			}
			else {
				if (password.empty()) {
					password.push_back(input[i]);
					it = password.end();
				}
				else {
					if (it == password.end()) {
						password.push_back(input[i]);
						it = password.end();
					}
					else
						password.insert(it, input[i]);
				}
			}
		}
		for (auto i : password)
			cout << i;
		cout << "\n";
	}

	return 0;
}
