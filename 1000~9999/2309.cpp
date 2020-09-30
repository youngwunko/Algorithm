#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	vector<int> length;
	int num;
	int total = 0;
	bool flag = 0;
	for (int i = 0; i < 9; i++) {
		cin >> num;
		length.push_back(num);
		total += num;
	}

	for (auto i = length.begin(); i < length.end(); i++) {
		if (total - *i > 100) {
			for (auto j = i + 1; j < length.end(); j++) {
				if (total - *i - *j == 100) {
					length.erase(j);
					length.erase(i);
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
	}
	sort(length.begin(), length.end());
	for (auto &i : length)
		cout << i << "\n";

	return 0;
}
