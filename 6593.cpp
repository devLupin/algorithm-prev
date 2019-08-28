#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int INF = 987654321;
const int SZ_ = 30;

typedef struct {
	int z, y, x;
	int dis;
}pos;

int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

bool visited[SZ_][SZ_][SZ_];
char map[SZ_][SZ_][SZ_];
int L, R, C;

int sz, sy, sx, ez, ey, ex;

int bfs(void) {
	memset(visited, false, sizeof(visited));

	int result = INF;
	queue<pos> q;
	q.push({ sz,sy,sx,0 });

	visited[sz][sy][sx] = true;

	while (!q.empty()) {
		pos cur = q.front();
		q.pop();

		if (cur.z == ez && cur.y == ey && cur.x == ex)
			result = (result < cur.dis) ? result : cur.dis;

		for (int dir = 0; dir < 6; dir++) {
			int nz = cur.z + dz[dir];
			int ny = cur.y + dy[dir];
			int nx = cur.x + dx[dir];

			if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C)
				continue;
			if (visited[nz][ny][nx])
				continue;
			if (map[nz][ny][nx] == '#')
				continue;

			visited[nz][ny][nx] = true;
			pos temp = { nz, ny, nx, cur.dis + 1 };
			q.push(temp);
		}
	}
	if (result == INF)
		return -1;

	return result;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	while (true) {
		cin >> L >> R >> C;

		if (!L && !R && !C)
			break;

		for (int i = 0; i < L; i++)
			for (int j = 0; j < R; j++)
				for (int k = 0; k < C; k++) {
					cin >> map[i][j][k];

					if (map[i][j][k] == 'S') {
						sz = i; sy = j; sx = k;
					}

					if (map[i][j][k] == 'E') {
						ez = i; ey = j; ex = k;
					}
				}

		int result = bfs();
		if (result > 0)
			cout << "Escaped in " << result << " minute(s).\n";
		else
			cout << "Trapped!\n";
	}
	return 0;
}