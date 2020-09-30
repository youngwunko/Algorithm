#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n[3];
	cin >> n[0] >> n[1] >> n[2];

	sort(n, n+3);

	if (n[0] == n[1] && n[1] == n[2]) {
		cout << n[0] * 1000 + 10000;
	}
	else if (n[0] == n[1] || n[1] == n[2]) {
		cout << n[1] * 100 + 1000;
	}
	else {
		cout << n[2] * 100;
	}

	return 0;
}
