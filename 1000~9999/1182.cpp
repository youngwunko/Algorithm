#include <iostream>
#include <vector>
using namespace std;

int N, S;
vector<int> nums;
int ans = 0;
int sum = 0;

void func(int select, int k, int cnt) {
	if (select == k) {
		if (sum == S) ans++;
		return;
	}

	int length = nums.size();
	for (int i = cnt; i < length; i++) {
		sum += nums[i];
		func(select, k + 1, i + 1);
		sum -= nums[i];
	}
}

int main(void) {
	cin >> N >> S;

	int num;
	for(int i = 0; i < N; i++){
		cin >> num; nums.push_back(num);
	}

	for (int i = 1; i <= N; i++)
		func(i, 0, 0);
	cout << ans << "\n";
	return 0;
}
