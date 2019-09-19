#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

typedef struct { int x, y, cnt; }info;
int n, m, src, dest;
bool p[101][101] = { false, }, visited[101][101] = { false, };
queue<info> q;

int bfs()
{
	int ret = -1;
	while (!q.empty()) {
		info cur = q.front();
		q.pop();

		if (cur.y == dest) {
			ret = cur.cnt;
			while (!q.empty())q.pop();
			break;
		}
		for (int i = 1; i <= n; i++) {
			if (p[cur.y][i] && !visited[cur.y][i] && cur.y != i) {
				q.push({ cur.y, i, cur.cnt + 1 });
				visited[cur.y][i] = true;
			}
		}
	}
	return ret;
}

int main()
{

	scanf("%d %d %d %d", &n, &src, &dest, &m);

	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d %d", &x, &y);
		p[x][y] = p[y][x] = true;
		if (src == x)
			q.push({ x,y,1 }), visited[x][y] = true;
		if (src == y)
			q.push({ y,x,1 }), visited[y][x] = true;
	}
	printf("%d\n", bfs());
	return 0;
}