#include<iostream>
#include<cstring>
using namespace std;
int r, c;
char map[21][21];
bool visited[21][21];
bool charVisited[26];
int result = 0;
void dfs(int x, int y, int number) {
	const int dy[] = { -1,1,0,0 };
	const int dx[] = { 0,0,-1,1 };

	result = (result < number) ? number : result;

	for (int i = 0; i < 4; i++) {
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX < 0 || nextY < 0 || nextX >= c || nextY >= r)
			continue;
		if (visited[nextY][nextX])
			continue;
		int idx = (int)(map[nextY][nextX] - 'A');
		if (charVisited[idx])
			continue;

		visited[nextY][nextX] = true;
		charVisited[idx] = true;
		dfs(nextX, nextY, number + 1);
		visited[nextY][nextX] = false;
		charVisited[idx] = false;
	}
}
int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	memset(visited, false, sizeof(visited));
	memset(charVisited, false, sizeof(charVisited));
	
	visited[0][0] = true;
	charVisited[map[0][0] - 'A'] = true;

	dfs(0, 0, 1);

	cout << result;
	
	return 0;
}