#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
	if (a.size() < b.size()) {
		return true;
	}
	else if (a.size() == b.size()) {
		if (a < b)
			return true;
	}
	return false;
}

int main(void) {
	int N; cin >> N;
	int cnt = N;
	vector<string> words;

	string input;
	while (N--) {
		cin >> input;
		words.push_back(input);
	}
	sort(words.begin(), words.end(), comp);

	string temp = " ";
	for (int i = 0; i < cnt; i++) {
		if (temp == words[i])
			continue;
		else
			temp = words[i];

		cout << words[i] << "\n";
	}

	return 0;
}