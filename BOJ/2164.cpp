#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	if (q.size() == 1) {
		cout << q.front();
		return 0;
	}

	while (!q.empty()) {
		q.pop();

		if (q.size() <= 1) {
			cout << q.front();
			q.pop();
			return 0;
		}

		int move = q.front();
		q.pop();
		q.push(move);
	}
	return 0;
}