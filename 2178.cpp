#include<queue>
#include<vector>
#include<iostream>
using namespace std;
int pos[][2] = { {0,1}, {0,-1}, {1,0}, {-1, 0} };
queue<pair<int, int>> q;
int maze[100][100];
int main(void)
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &maze[i][j]);

	q.push(make_pair(0, 0));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = cur.first + pos[i][0];
			int dy = cur.second + pos[i][1];

			if (dx >= 0 && dy >= 0 && dx < N && dy < M && maze[dx][dy] == 1) {
				q.push(make_pair(dx, dy));
				maze[dx][dy] = maze[cur.first][cur.second] + 1;
			}
		}
	}

	cout << maze[N - 1][M - 1];
	return 0;
}