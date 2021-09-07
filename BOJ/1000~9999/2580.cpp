#include <iostream>
#include <vector>

using namespace std;

int sudoku[10][10];
bool flag = 0;
vector<pair<int, int> > emp;
int cnt = 0;

void BT(int n) {
	if (n == cnt) {
		flag = 1;
		return;
	}

	int x = emp[n].first;
	int y = emp[n].second;
	vector<int> can_use(10);
	for (int i = 1; i <= 9; i++) {
		if (can_use[sudoku[i][y]] == 0)
			can_use[sudoku[i][y]] = 1;
		if (can_use[sudoku[x][i]] == 0)
			can_use[sudoku[x][i]] = 1;
	}

	int cx = ((x - 1) / 3) * 3 + 1;
	int cy = ((y - 1) / 3) * 3 + 1;
	for (int i = cx; i < cx + 3; i++) {
		for (int j = cy; j < cy + 3; j++) {
			if (can_use[sudoku[i][j]] == 0)
				can_use[sudoku[i][j]] = 1;
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (can_use[i] == 1) continue;
		sudoku[x][y] = i;
		BT(n + 1);		
		if (flag == 1)
			return;
		sudoku[x][y] = 0;
	}
}

int main(void) {
	int input;	
	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			cin >> input;
			if (input == 0) {
				emp.push_back({ x, y });
				cnt++;
			}
			sudoku[x][y] = input;
		}
	}

	BT(0);

	for (int x = 1; x <= 9; x++) {
		for (int y = 1; y <= 9; y++) {
			cout << sudoku[x][y] << " ";
		}
		cout << "\n";
	}

	return 0;
}