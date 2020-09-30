#include <iostream>
using namespace std;

int N, M;
int ans[10];
bool isused[10];

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!isused[i]) {
			ans[k] = i;
			func(k + 1);
		}
	}
}


int main(void) {
	cin >> N >> M;

	func(0);
	return 0;
}
