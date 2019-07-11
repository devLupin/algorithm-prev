#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
#include <string>
#include <map>
using namespace std;
int r, c;
bool isVisited[21][21];
char mapp[21][21];
bool isCharVisited[30];
int dxANDdy[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
int maxNumber = 0;
void dfs(int x, int y, int number) {
	maxNumber = max(maxNumber, number);
	for (auto i = 0; i < 4; i++) {
		int nextX = x + dxANDdy[i][0];
		int nextY = y + dxANDdy[i][1];
		if (0 <= nextX && nextX < c && 0 <= nextY && nextY < r) {
			if (!isVisited[nextX][nextY]) {
				char temp = mapp[nextX][nextY];
				int index = temp - 'A';
				if (!isCharVisited[index]) {
					isCharVisited[index] = true;
					isVisited[nextX][nextY] = true;
					dfs(nextX, nextY, number + 1);
					isCharVisited[index] = false;
					isVisited[nextX][nextY] = false;
				}

			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> r >> c;
	for (auto y = 0; y < r; y++) {
		for (auto x = 0; x < c; x++) {
			cin >> mapp[x][y];
		}
	}
	isCharVisited[mapp[0][0] - 'A'] = true;
	isVisited[0][0] = true;
	dfs(0, 0, 0);
	cout << maxNumber + 1;
	return 0;
}