#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int S[21][21];
bool isused[21];
int N, answer = 987654321;

void func(int pick, int k) {
	if (pick == N / 2) {
		int result1 = 0, result2 = 0;

		for (int x = 0; x < N; x++) {
			for (int y = x + 1; y < N; y++) {
				if (isused[x] == 0 && isused[y] == 0) {
					result1 += S[x][y];
				}
				else if(isused[x] == 1 && isused[y] == 1) {
					result2 += S[x][y];
				}
			}			
		}
		answer = min(answer, abs(result1-result2));
		return;
	}

	for (int i = k; i < N; i++) {
		if (isused[i]) continue;
		isused[i] = 1;
		func(pick + 1, i + 1);
		isused[i] = 0;
	}
}

int main(void) {
	cin >> N;
	int num;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> num;
			if (x < y)
				S[x][y] = num;
			else
				S[y][x] += num;
		}
	}

	func(0, 0);
	cout << answer << "\n";
	return 0;
}