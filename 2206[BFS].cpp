#include <iostream>
#include <queue>
using namespace std;

const int sz = 1001;
const int INF = 0x3f3f3f;

typedef struct {
	int y, x;
	int crush;
}pos;

int n, m, dest_y, dest_x;
char map[sz][sz];

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };
int visited[sz][sz][2] = { 0, };

int bfs()
{
	queue<pos> q;
	q.push({ 0, 0, 0});
	visited[0][0][0] = 1;
	
	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.y == dest_y && cur.x == dest_x) {
			return visited[cur.y][cur.x][cur.crush];
		}

		for (int dir = 0; dir < 4; dir++) {
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];
			int crush = cur.crush;

			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (visited[ny][nx][crush])
				continue;

			if (map[ny][nx] == '1' && !crush) {
				q.push({ ny, nx, 1 });
				visited[ny][nx][1] = visited[cur.y][cur.x][crush] + 1;
			}

			if (map[ny][nx] == '0') {
				q.push({ ny,nx,crush });
				visited[ny][nx][crush] = visited[cur.y][cur.x][crush] + 1;
			}
		}
	}

	return -1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++) {
			cin >> map[y][x];
		}
	dest_y = n - 1, dest_x = m - 1;

	cout << bfs();
}