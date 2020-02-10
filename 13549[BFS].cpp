#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	typedef pair<int, int> pi;
	const int sz = 100001;
	int n, k;
	cin >> n >> k;
	
	int ans = -1;
	bool visited[sz] = { false, };
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({ 0,n });
	visited[n] = true;

	while (!pq.empty()) {
		pi cur = pq.top();
		pq.pop();

		if (cur.second == k) {
			ans = cur.first;
		}

		if (cur.second * 2 < sz && !visited[cur.second * 2]) {
			pq.push({ cur.first, cur.second * 2 });
			visited[cur.second * 2] = true;
		}
		if (cur.second + 1 < sz && !visited[cur.second + 1]) {
			pq.push({ cur.first + 1 ,cur.second + 1 });
			visited[cur.second + 1] = true;
		}
		if (cur.second - 1 >= 0 && !visited[cur.second - 1]) {
			pq.push({ cur.first + 1, cur.second - 1 });
			visited[cur.second - 1] = true;
		}
	}

	cout << ans;
}