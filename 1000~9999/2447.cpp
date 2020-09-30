#include <iostream>

using namespace std;

int N;
char map[7000][7000];

void func(int k, int x, int y) {
	if (k == 1) {
		map[x][y] = '*';
		return;
	}

	int size = k / 3;
	for (int a = 0; a < 3; a++) {
		for (int b = 0; b < 3; b++) {
			if (a == 1 && b == 1) continue;
			func(size, x + a * size, y + b * size);
		}
	}
}

int main(void) {
	cin >> N;

	for (int x = 0; x < 7000; x++)
		fill(map[x], map[x] + 7000, ' ');
	func(N, 0, 0);

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++)
			cout << map[x][y];
		cout << "\n";
	}
	cout << "\n";
	return 0;
}
