#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int N; cin >> N;
	int cnt = N;
	vector<int> origin, nums;
	map<int, int> m;

	int num;
	while (N--) {
		cin >> num;
		origin.push_back(num);
		nums.push_back(num);
	}
	sort(nums.begin(), nums.end());

	int temp = nums[0];
	m[nums[0]] = 0;
	for (int i = 0; i < cnt; i++) {
		if (temp != nums[i]) {
			m[nums[i]] = m[temp] + 1;
			temp = nums[i];
		}
	}

	for (int i = 0; i < cnt; i++) {
		cout << m[origin[i]] << " ";
	}	

	return 0;
}