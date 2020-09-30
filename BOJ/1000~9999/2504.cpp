#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> s;
	string input;
	cin >> input;
	int result = 0;
	int temp = 1;
	bool error = 0;

    int length = input.size();
	for (int i = 0; i < length; i++) {
		if (input[i] == '(') {
			temp *= 2;
			s.push(input[i]);
		}
		else if (input[i] == '[') {
			temp *= 3;
			s.push(input[i]);
		}
		else if (input[i] == ')') {
			if (!s.empty() && s.top() == '(') {
				if (input[i - 1] == '(') {
					result += temp;
				}
				temp /= 2;
				s.pop();
			}
			else {
				error = 1;
				break;
			}
		}
		else if (input[i] == ']') {
			if (!s.empty() && s.top() == '[') {
				if (input[i - 1] == '[') {
					result += temp;
				}
				temp /= 3;
				s.pop();
			}
			else {
				error = 1;
				break;
			}
		}
	}
	if (s.empty() && error == 0)
		cout << result;
	else
		cout << 0;

	return 0;
}
