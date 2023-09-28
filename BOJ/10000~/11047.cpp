#include <iostream>

using namespace std;

int main(void) {
	int N, K;
	int coins[10];
	int coin, result = 0;

	cin >> N >> K;

	for (int i = 0; i < 10; i++) {
		cin >> coin;
		coins[i] = coin;
	}

	for (int i = N - 1; i >= 0; i--) {
		if (K / coins[i] != 0) {
			result += K / coins[i];
			K -= ((K / coins[i]) * coins[i]);
		}
		if (K == 0)
			break;
	}
	cout << result << "\n";
	return 0;
}
