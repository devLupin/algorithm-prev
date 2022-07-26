#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
int edge[1001][1001];
class Graph {
	int n;

public:
	Graph(int node) : n(node)
	{
		memset(edge, 0, sizeof(edge));
	}
	~Graph() {}
	void addEdge(int src, int dest) {
		edge[src][dest] += 1;
		edge[dest][src] += 1;
	}
	void BFS(int start);
	void DFS(int start);
};
void Graph::BFS(int start) {
	bool visited[1001];
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		visited[cur] = true;
		q.pop();

		cout << cur << " ";

		for (int i = 1; i <= n; i++) {
			if (visited[i])
				continue;
			if (edge[cur][i] == 0)
				continue;

			q.push(i);
			visited[i] = true;
		}
	}
	cout << endl;
}
void Graph::DFS(int start) {
	bool visited[1001];
	memset(visited, false, sizeof(visited));

	stack<int> s;
	s.push(start);
	visited[start] = true;
	cout << start << " ";

	while (!s.empty()) {

		int current_node = s.top();
		s.pop();
		for (int i = 1; i <= n; i++) {
			if (visited[i])
				continue;
			if (edge[current_node][i] == 0)
				continue;

			cout << i << " ";
			visited[i] = true;

			s.push(current_node);
			s.push(i);
			break;
		}
	}
	cout << endl;
}

int main(void)
{
	int node, edge, start;
	cin >> node >> edge >> start;
	Graph g(node);

	for (int i = 1; i <= edge; i++) {
		int src, dest;
		cin >> src >> dest;
		g.addEdge(src, dest);
	}

	g.DFS(start);
	g.BFS(start);

	return 0;
}