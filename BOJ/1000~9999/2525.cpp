#include <iostream>

using namespace std;

int main(void) {
	int h, m, cook_time;
	int num;
	cin >> h >> m >> cook_time;

	num = m + cook_time;
	if (num >= 60) {
		h += (num / 60);
		num %= 60;
	}	
	h = (h >= 24) ? (h - 24) : h;
	cout << h << " " << num;
	return 0;
}