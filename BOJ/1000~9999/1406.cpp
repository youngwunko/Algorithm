#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> sentence;
	string a;
	int M;
	char cmd, input_char;

	cin >> a >> M;
	for (char i : a) {
		sentence.push_back(i);
	}

	list<char>::iterator it = sentence.end();
	for (int i = 0; i < M; i++) {
		cin >> cmd;
		if (cmd == 'P') {
			cin >> input_char;
			sentence.insert(it, input_char);
		}
		else if (cmd == 'L') {
			if (it != sentence.begin())
				it--;
		}
		else if (cmd == 'D') {
			if (it != sentence.end())
				it++;
		}
		else if (cmd == 'B') {
			if (it != sentence.begin())
			{
				list<char>::iterator temp = it;
				sentence.erase(--it);
				it = temp;
			}
		}
	}

	for (auto& i : sentence)
		cout << i;
	cout << "\n";

	return 0;
}
