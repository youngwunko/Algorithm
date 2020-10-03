#include <iostream>

using namespace std;

int board[12][12];
bool isused1[22]; // x + y
bool isused2[22]; // y - x + N - 1
int ans[2];
int N;

void func(int row, int col, int cnt, int color) {
	if (col >= N) {
		row++;
		col = (row + color) % 2;
	}

	if (row >= N) {
		ans[color] = (cnt > ans[color] ? cnt : ans[color]);			
		return;
	}

	int check1 = row + col, check2 = col - row + N - 1;
	if (board[row][col] && !isused1[check1] && !isused2[check2]) {
		isused1[check1] = isused2[check2] = 1;
		func(row, col + 2, cnt + 1, color);
		isused1[check1] = isused2[check2] = 0;
	}
	func(row, col + 2, cnt, color);
}

int main(void) {
	cin >> N;

	int input;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> input;
			board[x][y] = input;
		}
	}
	func(0, 0, 0, 0);
	func(0, 1, 0, 1);
	cout << ans[0] + ans[1] << "\n";
	return 0;
}