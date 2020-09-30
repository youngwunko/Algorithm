#include <iostream>

using namespace std;
int result[10];
bool used[10];
int N, M;

void func(int *result, bool *used, int idx, int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) cout << result[i] + 1<< " ";
		cout << "\n";
		return;
	}

	for (int i = idx; i < N; i++) {
		result[k] = i;
		func(result, used, i, k + 1);
	}
	return;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	func(result, used, 0, 0);

	return 0;
}
