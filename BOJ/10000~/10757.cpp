#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	string in_a, in_b;
	int len_a, len_b, up = 0;
	vector<int> A, B;

	cin >> in_a >> in_b;
	len_a = in_a.size();
	len_b = in_b.size();

	if (len_a >= len_b) {
		for (string::reverse_iterator it = in_a.rbegin(); it != in_a.rend(); it++) {
			A.push_back(*it - '0');
		}
		for (string::reverse_iterator it = in_b.rbegin(); it != in_b.rend(); it++) {
			B.push_back(*it - '0');
		}
	}
	else {
		int temp = len_a;
		len_a = len_b;
		len_b = temp;

		for (string::reverse_iterator it = in_b.rbegin(); it != in_b.rend(); it++) {
			A.push_back(*it - '0');
		}
		for (string::reverse_iterator it = in_a.rbegin(); it != in_a.rend(); it++) {
			B.push_back(*it - '0');
		}
	}
	
	int p;
	for (p = 0; p < len_a; p++) {
		if(p < len_b)
			A[p] += B[p] + up;
		else {
			if (up == 0)
				break;
			A[p] += up;
		}			

		if (A[p] >= 10) {
			A[p] -= 10;
			up = 1;
		}
		else
			up = 0;
	}
	if (up == 1)
		A.push_back(1);
	
	for (vector<int>::reverse_iterator it = A.rbegin(); it != A.rend(); it++) {
		cout << *it;
	}
	cout << "\n";
	
	return 0;
}