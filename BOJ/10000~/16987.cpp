#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, answer = 0;
int armors[9];
int weights[9];

void func(int hand) {
	if (hand == N) {
		int result = 0;
		for (int i = 0; i < N; i++)
			if (armors[i] <= 0) result++;

		answer = max(answer, result);
		return;
	}

	if (armors[hand] <= 0) func(hand + 1);
	else {
		bool check = false;
		for (int i = 0; i < N; i++) {
			if (armors[i] <= 0 || hand == i) continue;
			check = true;

			armors[hand] -= weights[i];
			armors[i] -= weights[hand];
			func(hand + 1);
			armors[hand] += weights[i];
			armors[i] += weights[hand];
		}
		if (!check) func(N);
	}	
}

int main(void) {
	cin >> N;

	int armor, weight;
	for (int i = 0; i < N; i++) {
		cin >> armor >> weight;
		armors[i] = armor;
		weights[i] = weight;
	}

	func(0);

	cout << answer << "\n";
	return 0;
}