#include <iostream>
#include <queue>
using namespace std;

const int sz = 100001;
int n, k;
char map[2][sz];

typedef struct {
	int y, x, del;
}pos;

int bfs()
{
	bool visited[2][sz] = { false, };

	queue<pos> q;
	q.push({ 0 ,1, 0 });
	visited[0][1] = true;
	
	while (!q.empty()) {
		pos cur = q.front();
		int y = cur.y, x = cur.x;
		int del = cur.del;
		int tempY = !y;
		q.pop();

		if (x + 1 > n || x - 1 > n || x + k > n)
			return 1;

		if (x + 1 <= n && !visited[y][x + 1] && map[y][x + 1] == '1' && cur.del < x) {
		q.push({ y,x + 1, cur.del + 1 });
		visited[y][x + 1] = true;
		}
		if (x - 1 > 0 && !visited[y][x - 1] && map[y][x - 1] == '1' && cur.del < x) {
			q.push({ y, x - 1, cur.del + 1 });
			visited[y][x - 1] = true;
		}
		if (x + k <= n && !visited[tempY][x + k] && map[tempY][x + k] == '1' && cur.del < x) {
			q.push({ tempY, x + k, cur.del + 1 });
			visited[tempY][x + k] = true;
		}
	}
	return 0;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> map[0][i];
	for (int i = 1; i <= n; i++)
		cin >> map[1][i];

	cout << bfs();
	return 0;
}