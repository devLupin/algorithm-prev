#include<stack>
#include<vector>
#include<iostream>
#include<cstring>
#define ONE		'1'
using namespace std;
char map[26][26];
bool visited[26][26];
int house[630];
void sort(int sz) {
	for(int i=0; i<sz-1; i++)
		for (int j = i + 1; j < sz; j++) {
			if (house[i] > house[j]) {
				int temp = house[i];
				house[i] = house[j];
				house[j] = temp;
			}
		}
}

int main(void) 
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	memset(visited, false, sizeof(visited));

	const int dy[] = { -1, 1, 0, 0 };
	const int dx[] = { 0, 0, -1, 1 };

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	int number = ONE;
	int houseCnt = 0;
	memset(house, 0, sizeof(house));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '0' || visited[i][j] ||  map[i][j] > ONE)
				continue;
			stack<pair<int,int>> s;
			s.push(make_pair(i, j));
			map[i][j] = number;
			house[houseCnt]++;
			while (!s.empty()) {
				pair<int, int> cur = s.top();
				int ny = cur.first; int nx = cur.second;
				visited[ny][nx] = true;
				s.pop();

				for (int k = 0; k < 4; k++) {
					int y = ny + dy[k];
					int x = nx + dx[k];

					if (y < 0 || x < 0 || y >= n || x >= n)
						continue;
					if (map[y][x] == '0' || visited[y][x])
						continue;

					s.push(make_pair(y, x));
					visited[y][x] = true;
					map[y][x] = number;
					house[houseCnt]++;
				}
			}
			number++;
			houseCnt++;
		}
	}
	sort(houseCnt);
	cout << number - ONE << '\n';
	for (int i = 0; i < houseCnt; i++)
		cout << house[i] << '\n';


	return 0;
}