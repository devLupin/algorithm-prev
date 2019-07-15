#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int sz = 1001;

bool visited[sz];
bool edge[sz][sz];

int n, m;

void bfs(int v) {
	queue<int> q;
	q.push(v);
	while (!q.empty()) {
		int cur = q.front();
		visited[cur] = true;
		q.pop();

		for (int i = 1; i <= n; i++) {
			if (v == i)
				continue;
			if (visited[i])
				continue;
			if (!edge[cur][i])
				continue;

			q.push(i);
			visited[i] = true;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int src, dest;
		cin >> src >> dest;
		edge[src][dest] = true;
		edge[dest][src] = true;
	}

	int result = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (visited[i])
			continue;

		bfs(i);
		result++;
	}
	cout << result;
}