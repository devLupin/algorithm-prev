#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int dy[8] = { -1,-2,-2,-1,1,2,1,2 };
const int dx[8] = { -2,-1,1,2,-2,-1,2,1 };

int map[300][300] = { 0, };
bool visited[300][300] = { false, };
int sz = 0;

int dfs(int sx, int sy, int ex, int ey) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(sy, sx), 0));

	int ans = 0;

	while (!q.empty()) {
		pair<int, int> cur = q.front().first;
		int cur_cost = q.front().second;
		visited[cur.first][cur.second] = true;
		q.pop();

		if (cur.first == ey && cur.second == ex)
			ans = cur_cost;

		for (int dir = 0; dir < 8; dir++) {
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || nx < 0 || ny >= sz || nx >= sz)
				continue;
			if (visited[ny][nx])
				continue;

			q.push(make_pair(make_pair(ny, nx), cur_cost + 1));
			visited[ny][nx] = true;
		}
	}
	while (!q.empty())
		q.pop();
	return ans;
}

int main(void)
{
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		cin >> sz;

		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		cout << dfs(sx, sy, ex, ey) << endl;
	}
	return 0;
}