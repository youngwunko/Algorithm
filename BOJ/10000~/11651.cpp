#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> A, pair<int, int> B) {
	if (A.second < B.second) {
		return true;
	}
	else if (A.second == B.second) {
		if (A.first < B.first)
			return true;
	}
	return false;
}

int main(void) {
	int N; cin >> N;
	vector<pair<int, int> > pos;
	int x, y;

	while (N--) {
		cin >> x >> y;
		pos.push_back({ x, y });
	}
	sort(pos.begin(), pos.end(), comp);

	for (pair<int, int> p : pos) {
		cout << p.first << " " << p.second << "\n";
	}
	cout << "\n";

	return 0;
}