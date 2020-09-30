#include <iostream>
#include <vector>

using namespace std;

int N, M;
int ans = 0;
vector<int> card;
bool isused[102];
int pick[3];

void func(int num) {
	if (num == 3) {
		int sum = pick[0] + pick[1] + pick[2];
		if (sum <= M && ans < sum) ans = sum;
		return;
	}

	int len = card.size();
	for (int i = 0; i < len; i++) {
		if (isused[i]) continue;
		pick[num] = card[i];
		isused[i] = 1;
		func(num + 1);
		isused[i] = 0;
	}
}

int main(void) {
	cin >> N >> M;

	int num;
	while (N--) {
		cin >> num;
		card.push_back(num);
	}

	func(0);
	cout << ans << "\n";

	return 0;
}
