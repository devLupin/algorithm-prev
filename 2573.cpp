#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int dx[] = { 0,0,-1,1 };
const int dy[] = { -1,1,0,0 };

int map[300][300];
bool visited[300][300];
int n, m;

void nextYear(void) {
	int copy[300][300];
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			copy[y][x] = map[y][x];

	for (int y = 1; y < n - 1; y++)
		for (int x = 1; x < m - 1; x++)
			if (copy[y][x])
			{
				int cnt = 0;
				for (int i = 0; i < 4; i++)
				{
					int nextY = y + dy[i];
					int nextX = x + dx[i];

					if (copy[nextY][nextX] == 0)
						cnt++;
				}

				map[y][x] = max(copy[y][x] - cnt, 0);
			}
}

void dfs(int sy, int sx) {
	visited[sy][sx] = true;

	for (int i = 0; i < 4; i++) {
		int ny = sy + dy[i];
		int nx = sx + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (map[ny][nx] == 0)
			continue;
		if (visited[ny][nx])
			continue;

		dfs(ny, nx);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	int year = 0;
	while (true) {
		memset(visited, false, sizeof(visited));

		bool control = false;

		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = 0; j < m - 1; j++) {
				if (visited[i][j])
					continue;
				if (map[i][j] == -1 || map[i][j] == 0)
					continue;

				cnt++;
				if (cnt == 2) {
					control = true;
					break;
				}

				dfs(i, j);
			}
		}
		if (control)
			break;
		if (cnt == 0) {
			year = 0;
			break;
		}
		nextYear();
		year++;
	}

	cout << year << '\n';

	return 0;
}