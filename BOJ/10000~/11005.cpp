#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int N, B, temp;
	vector<char> answer;

	cin >> N >> B;

	while (N) {
		temp = N % B;

		if (temp < 10)
			answer.push_back('0' + temp);
		else
			answer.push_back('A' + temp - 10);
		N /= B;
	}

	int len = answer.size();
	for (int i = len - 1; i >= 0; i--) {
		cout << answer[i];
	}
	cout << "\n";

	return 0;
}