#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

const int size_ = 11;
int n, m;
int bx, by;
int rx, ry;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
char a[size_][size_];
bool visit[size_][size_][size_][size_];

struct info
{
	int rx, ry, bx, by;
};

int search() {
	queue<info> q;
	q.push({ rx,ry,bx,by });
	visit[rx][ry][bx][by] = 1;
	int ret = 0;
	while (q.size())
	{
		int len = q.size();
		while (len--)
		{
			info now = q.front();
			q.pop();
			if (a[now.rx][now.ry] == 'O' && a[now.rx][now.ry] != a[now.bx][now.by])	return ret;
			for (int i = 0; i < 4; i++)
			{
				int nrx = now.rx, nry = now.ry, nbx = now.bx, nby = now.by;
				while (a[nrx + dx[i]][nry + dy[i]] != '#' && a[nrx][nry] != 'O')
				{
					nrx += dx[i];
					nry += dy[i];
				}
				while (a[nbx + dx[i]][nby + dy[i]] != '#' && a[nbx][nby] != 'O')
				{
					nbx += dx[i];
					nby += dy[i];
				}
				if (nrx == nbx && nry == nby)
				{
					if (a[nrx][nry] == 'O') continue;
					if (abs(nrx - now.rx) + abs(nry - now.ry) < abs(nbx - now.bx) + abs(nby - now.by))
					{
						nbx -= dx[i];
						nby -= dy[i];
					}
					else
					{
						nrx -= dx[i];
						nry -= dy[i];
					}
				}
				if (visit[nrx][nry][nbx][nby]) continue;
				q.push({ nrx,nry,nbx,nby });
				visit[nrx][nry][nbx][nby] = 1;
			}
		}
		if (ret == 10) return -1;
		ret++;
	}
	return -1;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			scanf("\n%c", &a[i][j]);
			if (a[i][j] == 'B')	bx = i, by = j;
			if (a[i][j] == 'R')	rx = i, ry = j;
		}
	printf("%d\n", search());
	return 0;
}