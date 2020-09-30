#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		if (a == b)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
	return 0;
}
