#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef struct {
	int y, x, dis;
}pos;


const int dy[][3] = {
	{1, 1, 1}, {1, 1, 1}, {0,1,1}, {0,-1,-1},
	{-1,-1,-1}, {-1,-1,-1}, {0,-1,-1}, {0, 1, 1}
};
const int dx[][3] = {
	{0, -1, -1}, {0, 1, 1}, {1, 1, 1}, {1,1,1},
	{0, 1, 1}, {0, -1, -1}, {-1,-1,-1}, {-1,-1,-1}
};

int map[10][9];
bool visited[10][9];
int r1, c1, r2, c2;

int ry, rx;
bool move(int y, int x, int dir) {
	ry = y;
	rx = x;

	for (int i = 0; i < 2; i++) {
		ry = ry + dy[dir][i];
		rx = rx + dx[dir][i];

		if (ry == r2 && rx == c2)
			return false;
	}
	ry += dy[dir][2];
	rx += dx[dir][2];
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	memset(visited, false, sizeof(visited));

	cin >> r1 >> c1 >> r2 >> c2;
	
	queue<pos> q;
	q.push({ r1,c1,0 });
	visited[r1][c1] = true;

	while (!q.empty()) {
		pos cur = q.front();
		int cy = cur.y;
		int cx = cur.x;
		int cur_dis = cur.dis;
		q.pop();

		if (cy == r2 && cx == c2) {
			cout << cur_dis << '\n';
			while (!q.empty())q.pop();
			return 0;
		}

		for (int dir = 0; dir < 8; dir++) {
			int ny = -1, nx = -1;
			
			if (!move(cy, cx, dir))
				continue;
			else {
				ny = ry;
				nx = rx;
			}

			if (ny < 0 || nx < 0 || ny >= 10 || nx >= 9)
				continue;
			if (visited[ny][nx])
				continue;
			
			visited[ny][nx] = true;
			q.push({ ny,nx, cur_dis + 1 });		
		}
	}
	cout << -1 << '\n';
	return 0;
}