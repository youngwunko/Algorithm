#include <iostream>
using namespace std;

int N, r, c;

int Z(int n, int r, int c) {
	if (n == 0) return 0;
	int half = 1<<(n-1);

	if (r < half && c < half) return Z(n - 1, r, c);
	if (r < half && c >= half) return half*half + Z(n - 1, r, c - half);
	if (r >= half && c < half) return 2 * half*half + Z(n - 1, r - half, c);
	if (r >= half && c >= half) return 3 * half*half + Z(n - 1, r - half, c - half);
}

int main(void) {
	cin >> N >> r >> c;

	cout << Z(N, r, c) << "\n";
	return 0;
}
