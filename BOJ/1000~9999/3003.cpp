#include <iostream>

using namespace std;

int main(void) {
	int num;

	for (int i = 0; i < 2; i++) {
		cin >> num;
		cout << 1 - num << " ";
	}

	for (int i = 0; i < 3; i++) {
		cin >> num;
		cout << 2 - num << " ";
	}
	cin >> num;
	cout << 8 - num << "\n";
	return 0;
}