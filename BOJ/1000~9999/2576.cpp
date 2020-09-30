#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int total = 0;
	int min = 100;
	int num[7];
	for (int i = 0; i < 7; i++) {
		cin >> num[i];
		if (num[i] % 2 == 1) {
			total += num[i];
			if (min > num[i]) min = num[i];
		}
	}
	sort(num, num + 7);

	if (total == 0)
		cout << -1 << "\n";
	else
		cout << total << "\n" << min << "\n";

	return 0;
}
