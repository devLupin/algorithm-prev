#include<queue>
#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	for (int testcase = 0; testcase < tc; testcase++) {
		int n, target; cin >> n >> target;
		int cnt = 0;

		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int i = 0; i < n; i++) {
			int priority; cin >> priority;
			q.push({ i, priority });
			pq.push(priority);
		}

		while (!q.empty()) {
			int now_idx = q.front().first;
			int now_priority = q.front().second;
			q.pop();

			if (pq.top() == now_priority) {
				pq.pop(); cnt++;

				if (now_idx == target) {
					cout << cnt << '\n';
					break;
				}
			}
			else
				q.push({ now_idx, now_priority });
		}
	}
	return 0;
}