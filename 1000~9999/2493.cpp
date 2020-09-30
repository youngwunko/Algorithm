#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<pair<int, int> > s;
	int height, cnt = 0;

	int N; cin >> N;

	while (N--) {
		cin >> height;

		if (s.empty()) {
			cnt++;
			s.push({ height, cnt });
			cout << "0 ";
		}
		else {
			while (height > s.top().first){
				s.pop();
				if (s.empty()) break;
			}
			if(s.size() == 0)
				cout << "0 ";
			else
				cout << s.top().second << " ";
			cnt++;
			s.push({ height, cnt });
		}
	}
	cout << "\n";
	return 0;
}
