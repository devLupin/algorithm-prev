#include<queue>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
typedef pair<int, int> pi;

const int dy[] = { -2,-2,0,0,2,2 };
const int dx[] = { -1,1,-2,2,-1,1 };

int n, r1, c1, r2, c2;
bool visited[201][201];

int bfs()
{
	queue<pair<pi,int>> q;
	q.push({ {r1,c1}, 0 });
	visited[r1][c1] = true;

	while (!q.empty()) {
		auto cur = q.front().first;
		auto cost = q.front().second;
		q.pop();

		if (cur.first == r2 && cur.second == c2) {
			while (!q.empty())q.pop();
			return cost;
		}

		for (int dir = 0; dir < 6; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (visited[ny][nx])
				continue;

			q.push({ {ny,nx},cost + 1 });
			visited[ny][nx] = true;
		}
	}
	return -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> r1 >> c1 >> r2 >> c2;
	memset(visited, false, sizeof(visited));

	cout << bfs();
	return 0;
}