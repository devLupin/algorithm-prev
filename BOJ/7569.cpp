#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

typedef struct { int z, y, x; }pos;

const int d[][3] = {
	{0,0,-1}, {0,0,+1}, {0,1,0}, {0,-1,0},	//dy, dx
	{-1,0,0}, {1,0,0}	//dz
};
int n, m, h;
int map[100][100][100];
bool visited[100][100][100] = { false, };
queue<pos> q;

bool chk = false;
void bfs() {
	int sz = q.size();
	while (sz--) {
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 6; dir++) {
			int nz = cur.z + d[dir][0];
			int ny = cur.y + d[dir][1];
			int nx = cur.x + d[dir][2];

			if (nz < 0 || ny < 0 || nx < 0 || nz >= h || ny >= n || nx >= m)
				continue;
			if (map[nz][ny][nx] == -1 || visited[nz][ny][nx])
				continue;
			q.push({ nz,ny,nx }); visited[nz][ny][nx] = true;
			map[nz][ny][nx] = 1;
			
			chk = true;
		}
	}
}

bool check() {
	for (int z = 0; z < h; z++)for (int y = 0; y < n; y++)for (int x = 0; x < m; x++)
		if (map[z][y][x] == 0)
			return false;
	return true;
}

int main(void)
{
	int ans = 0;
	scanf("%d %d %d", &m, &n, &h);
	for (int z = 0; z < h; z++)for (int y = 0; y < n; y++)for (int x = 0; x < m; x++) {
		scanf("%d", &map[z][y][x]);
		if (map[z][y][x] == 1)
			q.push({ z,y,x }), visited[z][y][x] = true;
	}

	while (!q.empty()) { bfs(); ans++; }

	if (check()) {
		if (chk) printf("%d", ans - 1);
		else printf("0");
	}
	else printf("-1");

	return 0;
}