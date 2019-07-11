#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int r, c;
bool isVisited[21][21];
char map[21][21];
bool isCharVisited[30];
int dy[] = { -1,1,0,0 }; int dx[] = { 0,0,-1,1 };
int result = 0;
void dfs(int x, int y, int number) {
	int curX = x; int curY = y;
	int cost = number;

	if (result < cost)
		result = cost;

	for (int i = 0; i < 4; i++) {
		int nextX = curX + dx[i]; int nextY = curY + dy[i];

		if (nextX < 0 || nextY < 0 || nextX >= c || nextY >= r)
			continue;
		if (isVisited[nextY][nextX])
			continue;

		char temp = map[nextY][nextX];
		if (isCharVisited[temp - 'A'])
			continue;

		isCharVisited[temp - 'A'] = true;
		isVisited[nextY][nextX] = true;
		dfs(nextX, nextY, cost + 1);
		isCharVisited[temp - 'A'] = false;
		isVisited[nextY][nextX] = false;
	}
}
int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (auto y = 0; y < r; y++) {
		for (auto x = 0; x < c; x++) {
			cin >> map[x][y];
		}
	}
	memset(isVisited, false, sizeof(isVisited));
	memset(isCharVisited, false, sizeof(isCharVisited));

	isCharVisited[map[0][0] - 'A'] = true;
	isVisited[0][0] = true;
	dfs(0, 0, 1);
	cout << result;
	return 0;
}