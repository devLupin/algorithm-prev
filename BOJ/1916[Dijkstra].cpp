//https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

#include<queue>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> pi;

priority_queue<pi, vector<pi>, greater<pi>> pq;
list<pi>* adj;
vector<int> dist;

int V, E, src, dest;

void Dijkstra_using_pq(void)
{
	pq.emplace(make_pair(0, src));
	dist[src] = 0;

	while (!pq.empty()) {
		int u = pq.top().second;
		pq.pop();

		for (auto i : adj[u]) {
			int v = i.first;
			int weight = i.second;

			if (dist[v] > dist[u] + weight) {
				dist[v] = dist[u] + weight;
				pq.emplace(make_pair(dist[v], v));
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;

	adj = new list<pi>[V + 1];
	dist.resize(V + 1, INF);

	for (int i = 0; i < E; i++) {
		int u, v, w; cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
	}

	cin >> src >> dest;

	Dijkstra_using_pq();

	cout << dist[dest];
}