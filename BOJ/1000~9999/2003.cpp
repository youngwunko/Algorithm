#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	vector<int> arr;
	int N, M, answer = 0;
	cin >> N >> M;

	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	int pos1 = 0, pos2 = 0;
	int sum = 0;

	while(1) {		
		if (sum < M) {
			if (pos2 == N) break;
			sum += arr[pos2];
			pos2++;			
		}
		else {
			if (sum == M) {
				answer++;
			}
			sum -= arr[pos1];
			pos1++;
		}
	}

	cout << answer << "\n";
	return 0;
}