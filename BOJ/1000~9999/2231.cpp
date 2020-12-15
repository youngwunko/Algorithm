#include <iostream>

using namespace std;

int main(void) {
	int N; cin >> N;
	int num = 1, temp, result;

	while (1) {
		result = num;
		temp = num;
		while (temp) {
			result += (temp % 10);
			temp /= 10;
		}
		if (result == N) {
			break;
		}
		num++;
		if (num == 1000001) {
			break;
		}
	}
	if (num != 1000001)
		cout << num << "\n";
	else
		cout << 0 << "\n";

	return 0;
}