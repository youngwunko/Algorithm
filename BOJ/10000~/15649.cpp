#include <iostream>

using namespace std;
int result[10];
bool used[10];
int N, M;

void func(int *result, bool *used, int k) {
	if (k == M+1) {
		for (int i = 1; i <= M; i++) cout << result[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			result[k] = i;
			used[i] = true;

			func(result, used, k + 1);
			used[i] = false;
		}
	}
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(result, used, 1);

	return 0;
}
