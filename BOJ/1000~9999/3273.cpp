#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> nums;
	int n, x;
	cin >> n;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		nums.push_back(num);
	}
	cin >> x;

	sort(nums.begin(), nums.end());

	int result = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nums[i] + nums[j] == x)
				result++;
			else if (nums[i] + nums[j] > x)
				break;
		}
	}
	cout << result << "\n";
	return 0;
}