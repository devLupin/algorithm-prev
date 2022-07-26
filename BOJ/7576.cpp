#include<iostream>
#include<queue>
using namespace std;

const int sz = 1001;
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int n, m;
int map[sz][sz] = { 0, };

queue<pair<int, int>> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int result = -1;
	cin >> n >> m;

	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++) {
			cin >> map[y][x];
			
			if (map[y][x] == 1)
				q.push({ y,x });
	}

	while (!q.empty()) {
		auto cur = q.front();
		int cy = cur.first; int cx = cur.second;
		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 0 || nx < 0 || ny >= m || nx >= n)
				continue;
			if (map[ny][nx] == 0) {
				map[ny][nx] = map[cy][cx] + 1;
				q.push({ ny, nx });
			}
		}
	}

	for (int y = 0; y < m; y++)
		for (int x = 0; x < n; x++) {
			if (map[y][x] == 0) {
				cout << -1;
				return 0;
			}
			result = (result < map[y][x]) ? map[y][x] : result;
		}

	cout << result;
	return 0;
}