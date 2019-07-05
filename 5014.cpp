/* 5014 solved */
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
bool visited[10000001];
int upDown[2];
int main(void)
{
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	upDown[0] = U;
	upDown[1] = D * (-1);

	memset(visited, false, sizeof(visited));

	queue<pair<int, int>> q;
	q.push(make_pair(S, 0));
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		visited[cur.first] = true;
		q.pop();

		if (cur.first == G) {
			cout << cur.second;
			return 0;
		}

		for (int i = 0; i < 2; i++) {
			int stair = cur.first + upDown[i];

			if (stair > F || stair < 1 || visited[stair])
				continue;

			visited[stair] = true;
			q.push(make_pair(stair, cur.second + 1));
		}
	}
	cout << "use the stairs";
	return 0;
}
