#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int k = 1; k <= i; k++)
			cout << "*";
		for (int m = 1; m <= (N - i) * 2; m++)
			cout << " ";
		for (int k = 1; k <= i; k++)
			cout << "*";
		cout << "\n";
	}

	for (int i = 1; i <= N - 1; i++) {
		for (int k = 1; k <= N - i; k++)
			cout << "*";
		for (int m = 1; m <= i * 2; m++)
			cout << " ";
		for (int k = 1; k <= N - i; k++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}
