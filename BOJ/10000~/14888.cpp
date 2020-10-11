#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int picked[12];
int calc[4], isused[4];
int N;
int max_result = -1000000001;
int min_result = 1000000001;

void func(int pick) {
	if (pick == N - 1) {
		int result = nums[0];
		for (int i = 0; i < N - 1; i++) {
			if (picked[i] == 0) { // 더하기
				result += nums[i + 1];
			}
			else if (picked[i] == 1) { // 빼기
				result -= nums[i + 1];
			}
			else if (picked[i] == 2) { // 곱하기
				result *= nums[i + 1];
			}
			else { // 나누기
				result /= nums[i + 1];
			}
		}
		max_result = max(result, max_result);
		min_result = min(result, min_result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (isused[i] == calc[i]) continue;
		isused[i]++;
		picked[pick] = i;
		func(pick + 1);
		isused[i]--;
	}
}

int main(void) {
	cin >> N;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		nums.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		cin >> num;
		calc[i] = num;
	}
	func(0);
	cout << max_result << "\n";
	cout << min_result << "\n";
	return 0;
}