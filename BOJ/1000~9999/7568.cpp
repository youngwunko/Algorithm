#include <iostream>

using namespace std;

int person[52][4];

int main(void) {
	int N; cin >> N;
	int weight, height;

	for (int i = 0; i < N; i++) {
		cin >> weight >> height;
		person[i][0] = weight;
		person[i][1] = height;
	}

	for (int i = 0; i < N; i++) {
		int rank = 1;

		for (int k = 0; k < N; k++) {
			if (i == k) continue;
			if (person[i][0] < person[k][0] && person[i][1] < person[k][1])
				rank++;
		}
		person[i][2] = rank;
	}

	for (int i = 0; i < N; i++) {
		cout << person[i][2] << " ";
	}
	return 0;
}