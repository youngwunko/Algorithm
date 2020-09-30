#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string S;
	vector<int> alphabet(26);

	cin >> S;

	for (char a : S)
		alphabet[a - 'a']++;

	for (int i : alphabet)
		cout << i << " ";
	return 0;
}
