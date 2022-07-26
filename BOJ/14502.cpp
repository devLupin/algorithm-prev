#include<iostream>
#include<queue>
#include<cstring>
#define MAX(A, B) ((A > B) ? (A) : (B))
typedef enum { SPACE = 0, WALL, VIRUS };
using namespace std;

int map[9][9];
bool visited[9][9];
bool virusVisited[9][9];
int max_safeArea = -1;

int n, m;
int spaceCnt = 0;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int extendVirus(void) {
	memset(virusVisited, false, sizeof(virusVisited));
	int virusCnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == WALL)
				continue;
			if (virusVisited[i][j])
				continue;

			if (map[i][j] == VIRUS) {
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					pair<int, int> cur = q.front();
					int y = cur.first; int x = cur.second;
					virusVisited[y][x] = true;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];

						if (ny < 0 || nx < 0 || ny >= n || nx >= m)
							continue;
						if (virusVisited[ny][nx])
							continue;
						if (map[ny][nx] == WALL)
							continue;
						if (map[ny][nx] == VIRUS)
							continue;

						q.push(make_pair(ny, nx));
						virusVisited[ny][nx] = true;
						virusCnt++;
					}
				}
			}
		}
	}
	return virusCnt;
}

void dfs(int wallCnt) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (wallCnt == 3) {
				int cmp = (spaceCnt - 3) - extendVirus();
				max_safeArea = MAX(max_safeArea, cmp);
				return;
			}

			if (visited[i][j])
				continue;
			if (map[i][j] == WALL || map[i][j] == VIRUS)
				continue;

			map[i][j] = WALL;	visited[i][j] = true;
			dfs(wallCnt+1);
			map[i][j] = SPACE;		visited[i][j] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == SPACE)
				spaceCnt++;
		}

	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (map[i][j] == WALL || map[i][j] == VIRUS)
				continue;
			if (visited[i][j])
				continue;

			map[i][j] = WALL;
			visited[i][j] = true;
			
			dfs(1);

			map[i][j] = SPACE;
			visited[i][j] = false;
		}

	cout << max_safeArea;
	return 0;
}