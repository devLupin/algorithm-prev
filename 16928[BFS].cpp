#include<queue>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
typedef pair<int, int> pi;

bool visited[101];
vector<pi> v;		// x,y, either ladder or snake

const int dx[] = { 1,2,3,4,5,6 };

int bfs()
{
	queue<pi> q; q.push({ 1,0 });
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();

		if (cur.first == 100) {
			while (!q.empty())q.pop();
			return cur.second;
		}

		for (int dir = 0; dir < 6; dir++) {
			int next = cur.first + dx[dir];

			if (next > 100 || visited[next])
				continue;

			for (auto it = v.begin(); it != v.end(); ++it) {
				if ((*it).first == next) {
					next = (*it).second;
					break;
				}
			}
			q.push({ next, cur.second + 1 });
			visited[next] = true;
		}
	}
	return -1;
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int s, d; cin >> s >> d;
		v.push_back({ s,d });
	}

	memset(visited, false, sizeof(visited));
	cout << bfs();
}