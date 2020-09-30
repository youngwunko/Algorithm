#include <iostream>

using namespace std;

int main(void) {
	int N, call_time[20], Y = 0, M = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> call_time[i];
		Y += (call_time[i] / 30 + 1) * 10;
		M += (call_time[i] / 60 + 1) * 15;
	}
	if (Y == M)
		cout << "Y M " << Y << "\n";
	else
		if (Y < M)
			cout << "Y " << Y << "\n";
		else
			cout << "M " << M << "\n";

	return 0;
}
