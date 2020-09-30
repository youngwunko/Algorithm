#include <iostream>

using namespace std;

int N, ans = 0;
bool isused1[17]; // 같은 열 확인
bool isused2[34]; // 오른쪽 아래로 내려가는 대각선 확인
bool isused3[34]; // 오른쪽 위로 올라가는 대각선 확인

void func(int k) {
	if (k == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isused1[i]) continue;
		if (isused2[i - k + N - 1]) continue;
		if (isused3[i + k]) continue;

		isused1[i] = 1;
		isused2[i - k + N - 1] = 1;
		isused3[i + k] = 1;
		func(k + 1);
		isused1[i] = 0;
		isused2[i - k + N - 1] = 0;
		isused3[i + k] = 0;
	}
}

int main(void) {
	cin >> N;

	func(0);
	cout << ans << "\n";
	return 0;
}
