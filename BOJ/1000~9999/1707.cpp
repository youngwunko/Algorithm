#include <iostream>
#include <queue>

using namespace std;

int K, V, E;
vector<int> map[20001];
int color[20001];

bool check_graph()
{
	for (int k = 1; k <= V; k++)
	{
		for (int near : map[k])
		{
			if (color[k] == color[near])
				return false;
		}
	}
	return true;
}

void bfs(int cur)
{
	queue<int> q;
	q.push(cur);
	color[cur] = 1;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (int next : map[node])
		{
			if (color[next] == 0)
			{
				q.push(next);
				color[next] = 3 - color[node];
			}
		}
	}
}

int main(void)
{
	int node1, node2;
	cin >> K;
	for (int i = 1; i <= K; i++)
	{
		cin >> V >> E;

		for (int n = 1; n <= V; n++)
			map[n].clear();
		fill(color, color + V + 1, 0);

		for (int j = 1; j <= E; j++)
		{
			cin >> node1 >> node2;
			map[node1].push_back(node2);
			map[node2].push_back(node1);
		}

		for (int n = 1; n <= V; n++)
		{
			if(color[n] == 0)
				bfs(n);
		}

		if (check_graph())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}