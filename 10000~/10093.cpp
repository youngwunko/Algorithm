#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	long long A, B;
	cin >> A >> B;

	if (abs(B - A) == 0 || abs(B - A) == 1)
		cout << 0 << "\n";
	else
		cout << abs(B - A) - 1 << "\n";

	for (long long i = ((A < B) ? A : B) + 1; i < ((A < B) ? B : A); i++)
		cout << i << " ";

	return 0;
}
