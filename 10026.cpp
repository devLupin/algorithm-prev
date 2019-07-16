#include<iostream>
#include<cstring>
using namespace std;

const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };

const int sz = 100;
char no_map[sz][sz];
char yes_map[sz][sz];
bool no_visited[sz][sz];
bool yes_visited[sz][sz];

int n;
int no = 0;
int yes = 0;

void dfs(const char *opt, int sy, int sx) {
	for (int dir = 0; dir < 4; dir++) {
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		
		if (opt == "no") {
			if (no_visited[ny][nx])
				continue;
			if (no_map[sy][sx] != no_map[ny][nx])
				continue;
			no_visited[ny][nx] = true;
			dfs("no", ny, nx);
		}
		else if(opt == "yes") {
			if (yes_visited[ny][nx])
				continue;
			if (yes_map[sy][sx] != yes_map[ny][nx])
				continue;
			yes_visited[ny][nx] = true;
			dfs("yes", ny, nx);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			cin >> no_map[y][x];
			if (no_map[y][x] == 'G')
				yes_map[y][x] = 'R';
			else
				yes_map[y][x] = no_map[y][x];
		}

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			if (!no_visited[y][x]) {
				no_visited[y][x] = true;
				dfs("no", y, x);
				no++;
			}
			if (!yes_visited[y][x]) {
				yes_visited[y][x] = true;
				dfs("yes", y, x);
				yes++;
			}
		}

	cout << no << ' ' << yes;
	return 0;
}