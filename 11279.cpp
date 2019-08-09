#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	vector<int> v;
	priority_queue<int, vector<int>, less<int>> pq;
	int tc;		cin >> tc;
	for (int testcase = 0; testcase < tc; testcase++) {
		int temp; cin >> temp;

		if (temp == 0) {
			if (pq.empty())
				v.push_back(0);
			else {
				v.push_back(pq.top());
				pq.pop();
			}
		}
		else
			pq.push(temp);
	}
	for (auto it = v.begin(); it != v.end(); it++)
		cout << (*it) << '\n';
	return 0;
}