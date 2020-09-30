#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int ans[10];
bool isused[10];
vector<int> num;

void func(int k, int cnt) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}

	int length = num.size();
	for (int i = cnt; i < length; i++) {
		if (ans[k] == num[i]) continue;
		ans[k] = num[i];
		func(k + 1, i);
		ans[k + 1] = 0;
	}
}

int main(void) {
	cin >> N >> M;

	int n;
	while (N--) {
		cin >> n;
		num.push_back(n);
	}
	sort(num.begin(), num.end());

	func(0, 0);
	return 0;
}
