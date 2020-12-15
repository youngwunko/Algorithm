#include <iostream>

using namespace std;

int main(void) {
	int N; cin >> N;
	int num = 666, ans = 0, temp, cnt;
	bool flag;

	while (1) {
		temp = num;
		cnt = 0, flag = 0;

		while (temp) {
			if (temp % 10 == 6) {
				cnt++;
			}
			else {
				cnt = 0;
			}

			if (cnt == 3) {
				flag = 1;
				break;
			}
			temp /= 10;
		}
		if (flag == 1) {
			ans++;
			if (ans == N) {
				break;
			}
		}
		num++;
	}
	cout << num << "\n";

	return 0;
}