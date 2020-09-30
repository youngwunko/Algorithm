#include <iostream>

using namespace std;
#define LL long long

LL multi(LL A, LL B, LL C)
{
	if (B == 0) return 1;
	LL val = multi(A, B / 2, C);
	if (B % 2 == 1) return val * val % C * A % C;
	else		    return val * val % C;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B, C;
	cin >> A >> B >> C;
	cout << multi(A, B, C) << "\n";
	return 0;
}
