#include<iostream>
#include<deque>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	deque<int> dq;
	deque<int>::iterator it;

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++)
		dq.push_back(i);

	int ans = 0;
	for (int i = 0; i < m; i++) {
		int target; cin >> target;
		int size = dq.size();

		int idx = 1;
		for (it = dq.begin(); it != dq.end(); it++) {
			if ((*it) == target)
				break;
			idx++;
		}

		int left = idx - 1;
		int right = size - idx + 1;

		if (left < right) {
			for (int j = 1; j <= left; j++) {
				dq.push_back(dq.at(0));
				dq.pop_front();

				ans++;
			}
			dq.pop_front();
		}
		else {
			for (int j = 1; j <= right; j++) {
				dq.push_front(dq.at(size - 1));
				dq.pop_back();

				ans++;
			}
			dq.pop_front();
		}
	}
	cout << ans;
	return 0;
}