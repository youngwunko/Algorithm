#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int board[52][52];

int main(void) {
	int N, M; cin >> N >> M;
	int ans = 70, cnt1, cnt2, cmp1, cmp2, tmp1, tmp2;

	string input;
	for (int x = 0; x < N; x++) {
		cin >> input;
		for (int y = 0; y < M; y++) {
			if (input[y] == 'B')
				board[x][y] = 0;
			else
				board[x][y] = 1;
		}
	}

	for (int x = 0; x < N - 7; x++) {
		for (int y = 0; y < M - 7; y++) {
			cnt1 = 0, cnt2 = 0;
			cmp1 = 0, cmp2 = 1;

			for (int xt = x; xt < x + 8; xt++) {
				tmp1 = cmp1;
				tmp2 = cmp2;
				for (int yt = y; yt < y + 8; yt++) {
					if (tmp1 != board[xt][yt]) {
						cnt1++;
					}
					if (tmp2 != board[xt][yt]) {
						cnt2++;
					}
					tmp1 = tmp1 ^ 1;
					tmp2 = tmp2 ^ 1;
				}
				cmp1 = cmp1 ^ 1;
				cmp2 = cmp2 ^ 1;
			}
			ans = min(cnt1, ans);
			ans = min(cnt2, ans);
		}
	}
	cout << ans << "\n";
	return 0;
}