#include<queue>
#include<iostream>
#include<vector>
#include<list>
#include<cstdlib>
using namespace std;

typedef pair<int, int> pi;
const int INF = 0x3f3f3f3f;

list<pi>* adj;
vector<int> dist;
bool chk;
int n, m, w;

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
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		chk = true;

		cin >> n >> m >> w;

		adj = new list<pi>[n + 1];
		dist.resize(n + 1, INF);


		for (int i = 0; i < m; i++) {
			int u, v, weight; cin >> u >> v >> weight;
			adj[u].emplace_back(make_pair(v, weight));
			adj[v].emplace_back(make_pair(u, weight));
		}
		for (int i = 0; i < w; i++) {
			int u, v, weight; cin >> u >> v >> weight;
			adj[u].emplace_back(make_pair(v, weight * -1));
		}

		bellman_ford();
		if (chk) cout << "NO" << '\n';	
		else cout << "YES" << '\n';		// 문제를 보면 사이클이 있어야한다.

		delete[]adj;
	}
}