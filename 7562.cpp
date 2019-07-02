#include<queue>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
int main(void)
{	
	int pos[][2] = { {-1, +2}, {-2, +1}, {-2, -1}, {-1, -2},
					{+1, -2}, {+2, -1}, {+2, +1}, {+1, +2} };

	int n; int* result = NULL;
	cin >> n;

	result = new int[n];
	for (int i = 0; i < n; i++) {
		queue<pair<int, int>> q;
		pair<int, int> src, dest;
		int sz, x, y;

		int visited[301][301] = { 0, };

		cin >> sz;
		cin >> x >> y;
		src = make_pair(x, y);
		cin >> x >> y;
		dest = make_pair(x, y);

		q.push(src);
		while (!q.empty()) {
			pair<int, int> current = q.front();
			q.pop();

			if (current.second == dest.first && current.first == dest.second) {
				result[i] = visited[current.second][current.first];
				break;
			}

			for (int j = 0; j < 8; j++) {
				int dy = current.first + pos[j][1];
				int dx = current.second + pos[j][0];

				if (dx < 0 || dy < 0 || dx >= sz || dy >= sz)
					continue;
				if (visited[dy][dx])
					continue;

				q.push(make_pair(dy, dx));
				visited[dy][dx] = visited[current.second][current.first] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << result[i] << endl;
	
	return 0;
}