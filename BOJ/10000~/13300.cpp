#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int boy[7];
int girl[7];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, gender, grade, room = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> gender >> grade;
		if (gender == 0)
			girl[grade]++;
		else
			boy[grade]++;
	}

	for (int i = 1; i <= 6; i++) {
		if(boy[i] != 0)
			room += (boy[i] - 1) / K + 1;
		if (girl[i] != 0)
			room += (girl[i] - 1) / K + 1;
	}
	cout << room;

	return 0;
}
