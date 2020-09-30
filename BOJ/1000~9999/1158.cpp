#include <iostream>
#include <list>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	list<int> circle;
	for (int i = 1; i <= N; i++)
		circle.push_back(i);

	cout << "<";
	list<int>::iterator it = circle.begin();
	while (circle.size() != 1) {
		for (int i = 0; i < K - 1; i++) {
			if (it == circle.end())
				it = circle.begin();
			it++;
		}
		if (it == circle.end())
			it = circle.begin();

		cout << *it << ", ";
		it = circle.erase(it);
	}
	cout << circle.front() << ">\n";

	return 0;
}
