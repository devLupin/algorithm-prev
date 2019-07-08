#include<iostream>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
int main(void)
{
	int result = 0;
	int visited[101], edge[101][101];
	int n;
	int m;
	cin >> n >> m;

	memset(visited, false, sizeof(visited));
	memset(edge, 0, sizeof(edge));

	for (int i = 0; i < m; i++) {
		int src, dest;
		cin >> src >> dest;

		edge[src][dest] += 1;
		edge[dest][src] += 1;
	}

	stack<int> s;
	s.push(1);
	visited[1] = true;
	while (!s.empty()) {
		int cur = s.top();
		s.pop();

		for (int i = 1; i <= n; i++) {
			if (cur == i)
				continue;
			if (visited[i] || edge[cur][i] == 0)
				continue;

			result++;

			visited[i] = true;
			s.push(cur);
			s.push(i);
			break;
		}
	}
	
	cout << result;
	return 0;
}