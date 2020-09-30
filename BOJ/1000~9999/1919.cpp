#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int alpha1[26];
int alpha2[26];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i < s1.size(); i++)
		alpha1[s1[i] - 'a']++;
	for (int i = 0; i < s2.size(); i++)
		alpha2[s2[i] - 'a']++;

	int result = 0;
	for (int i = 0; i < 26; i++) {
		result += abs(alpha1[i] - alpha2[i]);
	}
	cout << result;

	return 0;
}
