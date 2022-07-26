#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> q;
	char result[1000001] = { NULL };

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int temp; cin >> temp;
		q.push(temp);
	}

	stack<int> s;
	int max = 0;
	int res_cnt = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (max < cur) {
			for (int i = max + 1; i <= cur; i++) {
				s.push(i);
				result[res_cnt++] = '+';
			}
			max = cur;
		}
		bool check = false;
		while (!s.empty()) {
			if (s.top() == cur) {
				check = true;
				result[res_cnt++] = '-';
				s.pop();
				break;
			}
			s.pop();
			result[res_cnt++] = '-';
		}

		if (!check) {
			cout << "NO" << '\n';
			return 0;
		}
	}

	for (int i = 0; i < res_cnt; i++)
		cout << result[i] << '\n';
	
	return 0;
}