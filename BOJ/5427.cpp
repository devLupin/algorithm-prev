#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

const int sz = 1000;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

char map[sz][sz];
bool visited[sz][sz] = { false, };
queue<pair<int, int>> fire;

int w, h;

int bfs(pair<int,int> start) {
	queue<pair<int, int>> q;
	visited[start.first][start.second] = true;
	q.push(start);

	int result = 0;

	while (!q.empty()) {
		int fireSize = fire.size();
		for (int f = 0; f < fireSize; f++) {
			int cy = fire.front().first;
			int cx = fire.front().second;
			fire.pop();

			for (int dir = 0; dir < 4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w)
					continue;
				if (map[ny][nx] == '.' || map[ny][nx] == '@') {
					map[ny][nx] = '*';
					fire.push({ ny, nx });
				}
			}
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++) {
			pair<int, int> cur = q.front();
			int cy = cur.first; int cx = cur.second;
			q.pop();

			if (cy == 0 || cy == h - 1 || cx == 0 || cx == w - 1)
				return result + 1;

			for (int dir = 0; dir < 4; dir++) {
				int ny = cy + dy[dir];
				int nx = cx + dx[dir];

				if (ny < 0 || nx < 0 || ny >= h || nx >= w)
					continue;
				if (visited[ny][nx])
					continue;
				
				if (map[ny][nx] == '.') {
					visited[ny][nx] = true;
					q.push({ ny, nx });
				}
			}
		}
		result++;
	}
	return -1;
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		while (!fire.empty())
			fire.pop();

		pair<int, int> start;
		memset(visited, false, sizeof(visited));

		cin >> w >> h;
		for(int y = 0; y<h; y++)
			for (int x = 0; x < w; x++) {
				cin >> map[y][x];

				if (map[y][x] == '@')
					start = { y,x };
				if (map[y][x] == '*')
					fire.push({ y,x });
			}
		int result = bfs(start);

		if (result == -1)
			cout << "IMPOSSIBLE" << '\n';
		else
			cout <<  result << '\n';
	}
	return 0;
}