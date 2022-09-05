#include <iostream>
#include <utility>
#include <string>

#define X first
#define Y second

using namespace std;

char video[64][64];
string result;

void compress(pair<int, int> start, int size) {
	if (size == 1) {
		(video[start.X][start.Y] == '0') ? result.append("0") : result.append("1");
		return;
	}

	char color = video[start.X][start.Y];
	int flag = 0;

	for (int x = 0; x < size; x++) {
		for (int y = 0; y < size; y++) {
			if (video[start.X + x][start.Y + y] != color) {
				result.append("(");
				compress({ start.X, start.Y }, size / 2);
				compress({ start.X, start.Y + (size / 2) }, size / 2);
				compress({ start.X + (size / 2), start.Y }, size / 2);
				compress({ start.X + (size / 2), start.Y + (size / 2) }, size / 2);
				result.append(")");
				flag = 1;
			}
			if (flag == 1)
				break;
		}
		if (flag == 1)
			break;
	}
	if (flag == 0) {
		(color == '0') ? result.append("0") : result.append("1");
		return;
	}
}

int main(void) {
	int N;
	string color;

	cin >> N;
	for (int x = 0; x < N; x++) {
		cin >> color;
		for (int y = 0; y < N; y++) {			
			video[x][y] = color[y];
		}
	}
	compress({ 0, 0 }, N);
	cout << result << "\n";
	return 0;
}