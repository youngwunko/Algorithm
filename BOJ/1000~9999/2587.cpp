#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int num[5];
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> num[i];
		total += num[i];
	}
	sort(num, num + 5);
	cout << total / 5 << "\n" << num[2] << "\n";

	return 0;
}
