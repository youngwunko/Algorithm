#include <iostream>
#include <algorithm>

using namespace std;

int calc[1000001];

int main(void) {
	int N; cin >> N;

	calc[2] = 1;
	calc[3] = 1;
	for (int i = 4; i <= N; i++) {
		if(i % 3 == 0 && i % 2 == 0)
			calc[i] = min(min(calc[i / 3], calc[i / 2]), calc[i - 1]) + 1;
		else if (i % 3 == 0) {
			calc[i] = min(calc[i / 3], calc[i - 1]) + 1;
		}
		else if (i % 2 == 0)
			calc[i] = min(calc[i / 2], calc[i - 1]) + 1;
		else
			calc[i] = calc[i - 1] + 1;
	}
	cout << calc[N] << "\n";
	   	 
	return 0;
}
