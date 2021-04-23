#include <iostream>
#include <vector>

using namespace std;

int A[202];
int isused[202];

int main(void)
{
	int N, K;	
	vector<int> robots;
	cin >> N >> K;

	int input, cnt = 0;
	for (int i = 1; i <= N * 2; i++)
	{
		cin >> input;
		A[i] = input;
		if (input == 0)
			cnt++;
	}

	int start = 1, end = N, stage = 1;
	while (1)
	{		
		if (!robots.empty() && robots[0] == end)
		{
			isused[robots[0]] = 0;
			robots.erase(robots.begin());
		}

		if (start == 1)
			start = 2 * N;
		else
			start--;

		if (end == 1)
			end = 2 * N;
		else
			end--;	

		//vector<int>::iterator it;

		for (int i = 0; i < robots.size(); i++)
		{
			if (robots[i] == end)
			{
				isused[robots[0]] = 0;
				robots.erase(robots.begin());
				i--;
			}
			else
			{
				int pos = robots[i];
				if (pos == 2 * N)
					pos = 1;
				else
					pos++;

				if (isused[pos] == 0 && A[pos] > 0)
				{
					isused[robots[i]] = 0;
					robots[i] = pos;
					isused[pos] = 1;
					A[pos]--;
					if (A[pos] == 0)
						cnt++;
				}
			}						
		}	

		if (isused[start] == 0 && A[start] > 0)
		{
			robots.push_back(start);
			isused[start] = 1;
			A[start]--;
			if (A[start] == 0)
				cnt++;
		}
		if (cnt >= K)
			break;
		stage++;
	}
	cout << stage << "\n";
	return 0;
}