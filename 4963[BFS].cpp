#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

typedef struct {
	int y, x;
}pos;

int map[51][51];
bool visited[51][51];
int n = 1, m = 1;

const int dy[] = { -1,1,0,0,-1,1,-1,1 };
const int dx[] = { 0,0,-1,1,-1,-1,1,1 };

queue<pos> temp;

int bfs() 
{
	int ret = 0;
	queue<pos> q;
	
	while (!temp.empty()) {
		pos t = temp.front();
		temp.pop();

		if (visited[t.y][t.x])
			continue;

		q.push({ t.y,t.x });
		visited[t.y][t.x] = true;

		while (!q.empty()) {
			pos cur = q.front();
			q.pop();

			for (int dir = 0; dir < 8; dir++) {
				int ny = cur.y + dy[dir];
				int nx = cur.x + dx[dir];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m)
					continue;
				if (visited[ny][nx])
					continue;
				if (map[ny][nx] == 1) {
					visited[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
		ret++;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	while (true) {
		cin >> m >> n;
		if (n == 0 && m == 0)
			break;

		memset(visited, false, sizeof(visited));

		for (int y = 0; y < n; y++) {
			for (int x = 0; x < m; x++) {
				cin >> map[y][x];
				if (map[y][x] == 1)
					temp.push({ y,x });
			}
		}

		cout << bfs() << '\n';
	}
}