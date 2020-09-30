#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; cin >> T;

	while (T--) {
		string cmd; cin >> cmd;
		int num; cin >> num;
		string input; cin >> input;
		bool err_flag = 0, fb_flag = 0;
		deque<int> nums;

		string temp;
		for (int i = 1; i < (int)input.size() - 1; i++) {
			if (input[i] == ',') {
				nums.push_back(stoi(temp));
				temp.resize(0);
				continue;
			}
			else {
				temp.push_back(input[i]);
			}
		}
		if(temp.size() != 0)
			nums.push_back(stoi(temp));

		for (auto &i : cmd) {
			if (i == 'R') {
				fb_flag = fb_flag ^ 1;
			}
			else {
				if (nums.empty()) {
					err_flag = 1;
					break;
				}
				else {
					if (fb_flag == 0) // 앞에서부터
						nums.pop_front();
					else
						nums.pop_back();
					num--;
				}
			}
		}

		if (err_flag == 1)
			cout << "error\n";
		else {
			cout << "[";
			if (fb_flag == 0) {
				for (int i = 0; i < num - 1; i++) {
					cout << nums.front() << ",";
					nums.pop_front();
				}
				if (!nums.empty())
					cout << nums.front();
			}
			else {
				for (int i = 0; i < num - 1; i++) {
					cout << nums.back() << ",";
					nums.pop_back();
				}
				if (!nums.empty())
					cout << nums.back();
			}
			cout << "]\n";
		}
	}
	return 0;
}
