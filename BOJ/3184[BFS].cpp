#include<queue>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
typedef pair<int, int> pi;

int r, c;
bool visited[250][250];
char map[250][250];

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

queue<pi> o, v;	//¾ç°ú ´Á´ë
int result[2] = { 0,0 };
void bfs()
{
	result[0] = o.size(), result[1] = v.size();

	while (!v.empty()) {
		auto v_cur = v.front();
		v.pop();

		if (visited[v_cur.first][v_cur.second])
			continue;

		queue<pi> q;
		q.push({ v_cur.first, v_cur.second });
		visited[v_cur.first][v_cur.second] = true;
		
		int sheep = 0, wolf = 1;
		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];

				if (ny < 0 || nx < 0 || ny >= r || nx >= c)
					continue;
				if (map[ny][nx] == '#' || visited[ny][nx])
					continue;

				if (map[ny][nx] == 'o') sheep++;
				if (map[ny][nx] == 'v') wolf++;
					
				q.push({ ny,nx }); visited[ny][nx] = true;
			}
		}
		if (sheep > wolf) result[1] -= wolf;
		else if (sheep <= wolf) result[0] -= sheep;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> r >> c;
	for (int y = 0; y < r; y++)
		for (int x = 0; x < c; x++) {
			cin >> map[y][x];
			
			if (map[y][x] == 'o')
				o.push({ y,x });
			if (map[y][x] == 'v') 
				v.push({ y,x });
		}

	memset(visited, false, sizeof(visited));
	bfs();
	cout << result[0] << ' ' << result[1];
	return 0;
}