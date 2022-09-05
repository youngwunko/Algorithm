#include <iostream>
#include <utility>

#define X first
#define Y second

using namespace std;

int white, blue;
int paper[128][128];

void check(pair<int, int> start, int size) {
	if (size == 1) {
		(paper[start.X][start.Y] == 0) ? white++ : blue++;
		return;
	}
	int color = paper[start.X][start.Y];
	int flag = 0;

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (paper[start.X + x][start.Y + y] != color) {
				check({ start.X, start.Y }, size / 2);
				check({ start.X + (size / 2), start.Y }, size / 2);
				check({ start.X, start.Y + (size / 2) }, size / 2);
				check({ start.X + (size / 2), start.Y + (size / 2) }, size / 2);
				flag = 1;
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
	if (flag == 0)
		(color == 0) ? white++ : blue++;
}

int main(void) {
	int N;
	int color;

	cin >> N;

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cin >> color;
			paper[x][y] = color;
		}
	}
	check({ 0, 0 }, N);
	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}