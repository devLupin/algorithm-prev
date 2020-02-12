#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
const int sz = 50;
const int INF = 987654321;
typedef pair<int, int> pi;

int map[sz][sz];

bool virus_chk[10] = { false, };
bool visited[sz][sz] = { false, };
vector<pi> virus;
vector<pi> located;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int bfs()
{
	queue<pi> q;
	
	for (int i = 0; i < located.size(); i++) {
		visited[located[i].first][located[i].second] = true;
		q.push({ located[i] });
	}

	int ret = 0;

	while (!q.empty()) {
		int q_sz = q.size();
		while (q_sz--) {
			pi cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= n)
					continue;
				if (!visited[ny][nx] && map[ny][nx] != 1) {
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
		if (q.size()) ret++;
	}

	for(int y=0; y<n; y++)
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 1)
				continue;
			if (!visited[y][x])
				return INF;
		}

	return ret;
}

int ans = INF;
void dfs(int cnt, int idx)
{
	if (cnt == m) {
		memset(visited, false, sizeof(visited));
		int cmp = bfs();
		ans = min(ans, cmp);
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (!virus_chk[i]) {
			virus_chk[i] = true;
			located.push_back(virus[i]);

			dfs(cnt + 1, i);
			
			virus_chk[i] = false;
			located.pop_back();
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];

			if (map[y][x] == 2) {
				virus.push_back({ y,x });
			}
		}

	memset(virus_chk, false, sizeof(virus_chk));

	dfs(0, 0);
	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}