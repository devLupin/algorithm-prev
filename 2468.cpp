#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

int map[100][100];
int visited[100][100];

int sz;
int result = 0;

int bfs(int max_height) {
	memset(visited, false, sizeof(visited));

	int numOfArea = 0;

	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz; j++) {
			if (visited[i][j])
				continue;
			if (map[i][j] < max_height) {
				visited[i][j] = true;
				continue;
			}

			numOfArea++;

			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			while (!q.empty()) {
				pair<int, int> cur = q.front();
				visited[cur.first][cur.second] = true;
				q.pop();

				for (int k = 0; k < 4; k++) {
					int ny = cur.first + dy[k];
					int nx = cur.second + dx[k];

					if (ny < 0 || nx < 0 || ny >= sz || nx >= sz)
						continue;
					if (visited[ny][nx])
						continue;
					if (map[ny][nx] < max_height)
						continue;

					q.push(make_pair(ny, nx));
					visited[ny][nx] = true;
				}
			}
		}
	}
	return numOfArea;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int maxHeight = -1;

	cin >> sz;
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < sz; j++) {
			cin >> map[i][j];
			
			maxHeight = (maxHeight < map[i][j]) ? map[i][j] : maxHeight;
		}

	for (int i = 1; i <= maxHeight; i++) {
		int temp = bfs(i);
		result = (result < temp) ? temp : result;
	}
	cout << result;
	
	return 0;
}