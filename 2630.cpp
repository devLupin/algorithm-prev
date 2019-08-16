#include<iostream>
using namespace std;

int map[129][129];
int n;

int blue = 0, white = 0;

void find(int len, int sy, int sx) {
	int cur = map[sy][sx];

	for (int y = sy; y < sy + len; y++) {
		for (int x = sx; x < sx + len; x++) {
			if (map[y][x] != cur) {
				find(len / 2, sy, sx);
				find(len / 2, sy + len / 2, sx);
				find(len / 2, sy, sx + len / 2);
				find(len / 2, sy + len / 2, sx + len / 2);

				return;
			}
		}
	}
	if (cur == 1)
		blue++;
	else
		white++;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	find(n, 0, 0);

	cout << white << '\n' << blue;
	return 0;
}