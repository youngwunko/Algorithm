#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int N; cin >> N;
	vector<int> nums;

	while (N) {
		nums.push_back(N % 10);
		N /= 10;
	}
	sort(nums.begin(), nums.end(), greater<int>());
	for (int num : nums) {
		cout << num;
	}
	cout << "\n";
	return 0;
}