#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

typedef struct info {
	int value;
	int worldDivision;
}Info;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

Info map[100][100];
bool visited[100][100];

int n;

void division_dfs(int sy, int sx, int cur_division) {

	map[sy][sx].worldDivision = cur_division;

	for (int dir = 0; dir < 4; dir++) {
		int ny = sy + dy[dir];
		int nx = sx + dx[dir];

		if (ny < 0 || nx < 0 || ny >= n || nx >= n)
			continue;
		if (visited[ny][nx])
			continue;
		if (map[ny][nx].value == 0)
			continue;

		visited[ny][nx] = true;
		map[ny][nx].worldDivision = cur_division;
		division_dfs(ny, nx, cur_division);
	}
}

int min_distance = 99999;
void bfs(int sy, int sx, int cur_division) {
	memset(visited, false, sizeof(visited));

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(sy, sx), 0));
	while (!q.empty()) {
		pair<int, int> cur = q.front().first;
		int y = cur.first;
		int x = cur.second;
		int distance = q.front().second;
		
		visited[y][x] = true;

		q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;

			if (map[ny][nx].value == 1 &&
				map[ny][nx].worldDivision != cur_division) 
				min_distance = (min_distance > distance) ? distance : min_distance;
				
			if (map[ny][nx].value == 1)
				continue;
			if (visited[ny][nx])
				continue;

			visited[ny][nx] = true;
			q.push(make_pair(make_pair(ny, nx), distance + 1));
		}
	}
		
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visited, false, sizeof(visited));

	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			cin >> map[y][x].value;
			map[y][x].worldDivision = 0;
		}

	int cur_division = 1;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++) {
			if (map[y][x].value == 0)
				continue;
			if (visited[y][x])
				continue;

			visited[y][x] = true;
			division_dfs(y, x, cur_division++);
		}

	memset(visited, false, sizeof(visited));
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			if (map[y][x].value == 0)
				continue;
			if (visited[y][x])
				continue;

			visited[y][x] = true;
			bfs(y, x, map[y][x].worldDivision);
		}
	}

	cout << min_distance;
	return 0;
}