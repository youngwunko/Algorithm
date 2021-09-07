#include <iostream>

using namespace std;

int main(void) {
	int N, divisor = 2;
	cin >> N;

	while (N != 1) {
		if (N % divisor == 0) {
			cout << divisor << "\n";
			N /= divisor;
		}
		else
			divisor++;
	}
	return 0;
}