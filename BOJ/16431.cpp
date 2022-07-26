#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef struct {
	int y, x;
	int dis;
} Pos;

const int b_dy[] = { -1,1,0,0,1,1,-1,-1 };
const int b_dx[] = { 0,0,-1,1,-1,1,1,-1 };
const int d_dy[] = { -1,1,0,0 };
const int d_dx[] = { 0,0,-1,1 };

bool visited[1001][1001] = { false, };

int ay, ax, by, bx;
int dest_y, dest_x;

int bfs(int sy, int sx, const char *name) {
	memset(visited, false, sizeof(visited));

	int* dy = NULL;
	int* dx = NULL;
	int dirDistance;
	if (!strcmp("bessie", name)) {
		dirDistance = 8;
		dy = new int[8];
		dx = new int[8];

		for (int i = 0; i < 8; i++) {
			dy[i] = b_dy[i];
			dx[i] = b_dx[i];
		}
	}
	else {
		dirDistance = 4;
		dy = new int[4];
		dx = new int[4];

		for (int i = 0; i < 4; i++) {
			dy[i] = d_dy[i];
			dx[i] = d_dx[i];
		}
	}

	int result = 98765432;

	queue<Pos> q;
	q.push({ sy, sx, 0 });
	visited[sy][sx] = true;

	while (!q.empty()) {
		Pos cur = q.front();
		int cy = cur.y; int cx = cur.x;
		int dis = cur.dis;
		q.pop();

		if (cy == dest_y && cx == dest_x)
			result = (result < dis) ? result : dis;

		for (int dir = 0; dir < dirDistance; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];

			if (ny < 1 || nx < 1 || ny > 1000 || nx > 1000)
				continue;
			if (visited[ny][nx])
				continue;

			q.push({ ny,nx, dis + 1 });
			visited[ny][nx] = true;
		}
	}
	delete[]dy;
	delete[]dx;

	return result;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> ay >> ax;
	cin >> by >> bx;
	cin >> dest_y >> dest_x;

	int bessie = bfs(ay, ax, "bessie");
	int daisy = bfs(by, bx, "daisy");

	if (bessie < daisy)
		cout << "bessie";
	else if (bessie > daisy)
		cout << "daisy";
	else
		cout << "tie";
	
	return 0;
}