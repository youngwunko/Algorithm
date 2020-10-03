#include <iostream>

using namespace std;

int number[17];
int answer[17];
int k;

void func(int pick, int start) {
	if (pick == 6) {
		for (int i = 0; i < 6; i++) {
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = start; i < k; i++) {
		answer[pick] = number[i];
		func(pick + 1, i + 1);
	}
}

int main(void) {
	int num;
	while (1) {
		cin >> k;
		if (k == 0) return 0;
		else {
			for (int i = 0; i < k; i++) {
				cin >> num;
				number[i] = num;
			}
			func(0, 0);
			cout << "\n";
		}
	}
}