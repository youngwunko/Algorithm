#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char answer[16];
string crypt;

int L, C;
int vowel = 0, unvowel = 0;

void func(int pick, int start) {
	if (pick == L) {
		if(vowel >= 1 && unvowel >= 2) {
			for (int i = 0; i < L; i++) {
				cout << answer[i];
			}
			cout << "\n";
		}
		return;
	}

	for (int i = start; i < C; i++) {
		answer[pick] = crypt[i];
		if (crypt[i] == 'a' || crypt[i] == 'e' || crypt[i] == 'i' || crypt[i] == 'o' || crypt[i] == 'u') {
			vowel++;
			func(pick + 1, i + 1);
			vowel--;
		}
		else {
			unvowel++;
			func(pick + 1, i + 1);
			unvowel--;
		}		
	}
}

int main(void) {
	cin >> L >> C;

	char input;
	for(int i = 0; i < C; i++) {
		cin >> input;
		crypt.push_back(input);
	}
	sort(crypt.begin(), crypt.end());
	func(0, 0);
	return 0;
}