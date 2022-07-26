#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int map[50][50];
bool visited[50][50];
int result[50];
int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	const int dy[] = { -1, 1, 0, 0 };
	const int dx[] = { 0,0,-1,1 };

	int TC;
	cin >> TC;
	memset(result, 0, sizeof(result));
	for (int i = 0; i < TC; i++) {
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));

		int n, m, num;
		cin >> n >> m >> num;		// n: 가로 , m : 세로

		for (int j = 0; j < num; j++) {
			int x, y;	cin >> x >> y;
			map[y][x] = 1;
		}

		for (int j = 0; j < m; j++) {
			for (int k = 0; k < n; k++) {
				if (visited[j][k])
					continue;
				if (map[j][k] == 0)
					continue;

				result[i]++;

				stack<pair<int, int>> s;
				s.push(make_pair(j, k));
				while (!s.empty()) {
					pair<int, int> cur = s.top();
					s.pop();
					visited[cur.first][cur.second] = true;

					for (int l = 0; l < 4; l++) {
						int ny = cur.first + dy[l];
						int nx = cur.second + dx[l];

						if (map[ny][nx] == 0)
							continue;

						if (visited[ny][nx])
							continue;
						if (nx < 0 || nx >= n || ny < 0 || ny >= m)
							continue;

						s.push(make_pair(ny, nx));
						visited[ny][nx] = true;
					}
				}
			}
		}
	}
	for (int i = 0; i < TC; i++)
		cout << result[i] << '\n';
	return 0;
}