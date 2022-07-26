#include <list>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int, int> pi;
const int INF = 0x3f3f3f3f;

int n, m;
list<pi>* adj;
vector<int> dist;
bool chk = true;

void bellman_ford(void)
{
	dist[1] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			for (auto k : adj[j])
				if (dist[j] != INF && dist[k.first] > dist[j] + k.second)
					dist[k.first] = dist[j] + k.second;

	for (int i = 1; i <= n; i++)
		for (auto j : adj[i])
			if (dist[i] != INF && dist[i] + j.second < dist[j.first])
				chk = false;

}

int main(void)
{
	scanf("%d %d", &n, &m);

	adj = new list<pi>[n + 1];
	dist.resize(n + 1, INF);

	while (m--) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(make_pair(v, w));
	}

	bellman_ford();
	if (!chk)
		printf("-1");
	else {
		for (int i = 2; i <= n; i++)
			printf("%d\n", dist[i] != INF ? dist[i] : -1);
	}

	delete[]adj;
	return 0;
}