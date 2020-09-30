#include <iostream>

using namespace std;

int H, M;

int main(void) {
	cin >> H >> M;

	int setH, setM;

	if (M < 45) {
		setM = M + 15;
		if (H == 0) {
			setH = 23;
		}
		else
			setH = --H;
	}
	else {
		setM = M - 45;
		setH = H;
	}
	cout << setH << " " << setM << "\n";

	return 0;
}
