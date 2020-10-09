#include <iostream>
#include <string>

using namespace std;

int wheel[4][8];
int standard[4];
int isrotate[4];

void func(int select, int rotate) {
	standard[select] -= rotate;
	if (standard[select] == -1) {
		standard[select] = 7;
	}
	else if (standard[select] == 8) {
		standard[select] = 0;
	}
}

int check(int w1, int w2, int rotate) {
	int c1 = standard[w1] + 2;
	int c2 = standard[w2] + 6;

	if (c1 > 7) c1 -= 8;
	if (c2 > 7) c2 -= 8;

	if (wheel[w1][c1] ^ wheel[w2][c2]) { // 서로 극이 다를 때
		int select = (isrotate[w1] == 0) ? w1 : w2;
		return select;
	}
	else
		return -1;
}

int main(void) {
	string input;
	for (int i = 0; i < 4; i++) {
		cin >> input;
		for (int j = 0; j < 8; j++)
			wheel[i][j] = (int)input[j] - 48;
	}

	int K; cin >> K;
	int pick, rotate;	
	while (K--) {
		fill(isrotate, isrotate + 4, 0);
		cin >> pick >> rotate;
		isrotate[pick - 1] = rotate;

		if (pick == 1 || pick == 2) {
			for (int i = 0; i < 3; i++) {
				if (!isrotate[i] && !isrotate[i + 1]) {
					break;
				}
				else {
					int change = check(i, i + 1, rotate);
					if (change >= 0) {
						isrotate[change] = (((pick-1) % 2) ^ (change % 2)) ? rotate * -1 : rotate;
					}
				}				
			}
		}
		else {
			for (int i = 3; i > 0; i--) {
				if (!isrotate[i - 1] && !isrotate[i]) {
					break;
				}
				else {
					int change = check(i - 1, i, rotate);
					if (change >= 0) {
						isrotate[change] = (((pick-1) % 2) ^ (change % 2)) ? rotate * -1 : rotate;
					}
				}				
			}
		}

		for (int i = 0; i < 4; i++) {
			if (isrotate[i] != 0) {
				func(i, isrotate[i]);
			}
		}
	}
	cout << wheel[0][standard[0]] + wheel[1][standard[1]]*2 + wheel[2][standard[2]]*4 + wheel[3][standard[3]]*8 << "\n";
	return 0;
}