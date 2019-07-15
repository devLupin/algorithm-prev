#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int sz = 100001;
bool visited[sz];

int bfs(int src, int dest) {
	queue<int> q;
	q.push(src);

	int cost = 0;
	while (true) {
		int size = q.size();

		for (int i = 0; i < size; i++) {
			int cur = q.front();
			q.pop();

			if (cur == dest)
				return cost;

			if (cur > 0 && !visited[cur - 1]) {
				q.push(cur - 1);
				visited[cur - 1] = true;
			}
			if (cur < sz && !visited[cur + 1]) {
				q.push(cur + 1);
				visited[cur + 1] = true;
			}
			if (cur * 2 < sz && !visited[cur * 2]) {
				q.push(cur * 2);
				visited[cur * 2] = true;
			}
		}
		cost++;
	}
}

int main(void)
{
	int src, dest;

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> src >> dest;
	memset(visited, false, sizeof(visited));

	cout << bfs(src, dest);

	return 0;
}