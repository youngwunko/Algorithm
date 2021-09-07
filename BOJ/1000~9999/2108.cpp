#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cnt[8100];

int main(void) {
	int N; cin >> N;
	vector<int> nums;

	int total = 0, input;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		total += input;
		nums.push_back(input);
		cnt[input + 4000]++;
	}
	sort(nums.begin(), nums.end());

	cout << round((double)total / N) << "\n";
	cout << nums[N / 2] << "\n";

	int max = 0, most = -1, flag = 0;
	for (int i = 0; i < 8100; i++) {
		if (cnt[i] > max) {
			max = cnt[i];
			most = i;
			flag = 0;
		}
		else if (cnt[i] == max && flag == 0) {
			most = i;
			flag = 1;
		}
	}
	cout << most - 4000 << "\n";
	cout << nums[N - 1] - nums[0] << "\n";

	return 0;
}