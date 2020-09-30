#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int m = 1; m <= N - i; m++)
			cout << " ";
		for (int k = 1; k <= i * 2 - 1; k++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}
