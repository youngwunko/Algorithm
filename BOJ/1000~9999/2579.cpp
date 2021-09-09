#include <iostream>
#include <algorithm>

using namespace std;

int stair[302];
int score[302];

int main(void) {
	int N;  cin >> N;

	int input;
	for (int i = 1; i <= N; i++) {
		cin >> input;
		stair[i] = input;
	}
	
	score[1] = stair[1];
	score[2] = stair[1] + stair[2];
	score[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	for(int n = 4; n <= N; n++)
		score[n] = max(score[n - 3] + stair[n - 1] + stair[n], score[n - 2] + stair[n]);
	cout << score[N] << "\n";
	   	 
	return 0;
}