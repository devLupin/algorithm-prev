#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int sz = 100;
int src[sz][sz];
bool visited[sz][sz];
int n;

int bfs(int s, int d) {
	memset(visited, false, sizeof(visited));

	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		for (int i = 0; i < n; i++) {
			if (cur == i)
				continue;
			if (src[cur][i] == 0)
				continue;
			if (visited[cur][i])
				continue;

			if (i == d)
				return true;

			visited[cur][i] = true;
			q.push(i);
		}
	}
	return 0;
}

int main(void)
{	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> src[i][j];
		}

	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << bfs(i,j) << ' ';
		cout << '\n';
	}
	
	return 0;
}