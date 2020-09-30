#include <iostream>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = N; i >= 1; i--) {
		for (int k = 0; k < N - i; k++)
			cout << " ";
		for (int m = 1; m <= i * 2 - 1; m++)
			cout << "*";
		cout << "\n";
	}

	return 0;
}
