#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;
tuple<int, int, int> tp[100001];
int parent[10001];

bool comp(tuple<int, int, int> &a, tuple<int, int, int> &b)
{
	return get<2>(a) < get<2>(b);
}

int find(int u)
{
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}

int main(void)
{
	int V, E;
	cin >> V >> E;

	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		tp[i] = tie(A, B, C);
	}

	for (int i = 1; i <= V; i++)
		parent[i] = i;

	sort(tp, tp + E, comp);

	int total = 0;
	int cnt = 0;
	for (int i = 0; i < E; i++)
	{
		int from, to, val;
		tie(from, to, val) = tp[i];

		int u = find(from);
		int v = find(to);
		if (u != v)
		{
			parent[u] = v;
			total += val;
			cnt++;
		}
		if (cnt == V - 1)
			break;
	}
	cout << total << "\n";
	return 0;
}