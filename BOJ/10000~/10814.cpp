#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, pair<int, string> > a, pair<int, pair<int, string> > b) {
	if (a.second.first < b.second.first) {
		return true;
	}
	else if (a.second.first == b.second.first) {
		if (a.first < b.first)
			return true;
	}
	return false;
}

int main(void) {
	int N; cin >> N;
	int order = 1;
	vector<pair<int, pair<int, string> > > members;

	int age;
	string name;
	while (N--) {
		cin >> age >> name;
		members.push_back({ order++, {age, name} });
	}
	sort(members.begin(), members.end(), comp);

	for (auto member : members) {
		cout << member.second.first << " " << member.second.second << "\n";
	}

	return 0;
}