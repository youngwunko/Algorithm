#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	unordered_map<string, int> com;
	for (string person : completion) {
		com[person]++;
	}

	for (string person : participant) {
		com[person]--;
		if (com[person] == -1) return person;
	}
}

int main(void) {
	vector<string> participant = {"kiki", "leo", "kiki", "eden"};
	vector<string> completion = {"eden", "kiki", "leo" };

	cout << solution(participant, completion) << "\n";
	return 0;
}