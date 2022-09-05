#include <iostream>
#include <utility>

#define X first
#define Y second

using namespace std;

int minus_one, zero, one;
int paper[2187][2187];

void cut(pair<int, int> start, int size) {
	if (size == 1) {
		(paper[start.X][start.Y] == -1) ? minus_one++ : ((paper[start.X][start.Y] == 0) ? zero++ : one++);
		return;
	}

	int color = paper[start.X][start.Y];
	int flag = 0;
	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (paper[start.X + x][start.Y + y] != color) {
				cut({ start.X,					 start.Y },					 size / 3);
				cut({ start.X,					 start.Y + (size / 3)},		 size / 3);
				cut({ start.X,					 start.Y + (size / 3) * 2},  size / 3);
				cut({ start.X + (size / 3),		 start.Y },					 size / 3);
				cut({ start.X + (size / 3),		 start.Y + (size / 3) },	 size / 3);
				cut({ start.X + (size / 3),		 start.Y + (size / 3) * 2 }, size / 3);
				cut({ start.X + (size / 3) * 2,  start.Y },					 size / 3);
				cut({ start.X + (size / 3) * 2,  start.Y + (size / 3) },	 size / 3);
				cut({ start.X + (size / 3) * 2,  start.Y + (size / 3) * 2 }, size / 3);
				flag = 1;
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
	if (flag == 0)
		(color == -1) ? minus_one++ : ((paper[start.X][start.Y] == 0) ? zero++ : one++);
}

int main(void) {
	int N;
	int num;

	cin >> N;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> num;
			paper[x][y] = num;
		}
	}
	cut({ 0, 0 }, N);
	cout << minus_one << "\n";
	cout << zero << "\n";
	cout << one << "\n";

	return 0;
}