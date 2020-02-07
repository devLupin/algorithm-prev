#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int n, m, map[8][8];
bool chk[8][8];

vector<pi> virus;

int bfs()
{
	bool visited[8][8] = { false, };
	queue<pi> q;

	int copy[8][8];
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			copy[y][x] = map[y][x];

	for (auto it = virus.begin(); it != virus.end(); ++it)
		q.push(*it);

	while (!q.empty()) {
		int sz = q.size();
		
		while (sz--) {
			pi cur = q.front();
			q.pop();

			visited[cur.first][cur.second] = true;

			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (copy[ny][nx] == 0 && !visited[ny][nx]) {
					copy[ny][nx] = 2;
					q.push({ ny,nx });
				}
			}
		}
	}

	int ret = 0;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (copy[y][x] == 0)
				ret++;

	return ret;
}

int ans = -987654321;
void dfs(int cnt, int cy, int cx)
{
	if (cnt == 3) {
		int cmp = bfs();
		if (ans < cmp) ans = cmp;
		return;
	}

	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			if (chk[y][x] || map[y][x] != 0)
				continue;

			chk[y][x] = true; map[y][x] = 1;
			dfs(cnt + 1, y, x);
			chk[y][x] = false; map[y][x] = 0;
		}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	
	cin >> n >> m;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
			chk[y][x] = false;

			if (map[y][x] == 2)
				virus.push_back({ y,x });
		}

	dfs(0, 0, 0);

	cout << ans;
}