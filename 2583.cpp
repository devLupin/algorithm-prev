#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int M, N, K;
bool map[100][100] = { 0 };
bool visited[100][100] = { 0 };

int dfs(int y, int x) {

	int cnt = 1;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= M || nx < 0 || nx >= N)
			continue;

		if (map[ny][nx] || visited[ny][nx])
			continue;

		visited[ny][nx]++;
		cnt += dfs(ny, nx);
	}

	return cnt;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> M >> N >> K;

	int sx, sy, ex, ey;
	for (int i = 0; i < K; i++) {
		cin >> sx >> sy >> ex >> ey;

		for (int x = sx; x < ex; x++)
			for (int y = sy; y < ey; y++)
				map[y][x]++;

	}

	vector<int> result;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j] && !visited[i][j]) {
				visited[i][j]++;
				result.push_back(dfs(i, j));
			}
		}
	}

	cout << result.size() << endl;

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}
