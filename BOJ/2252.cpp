//https://terms.naver.com/entry.nhn?docId=3579618&cid=59086&categoryId=59093
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int indegree[32001] = { 0, };
vector<int> v[32001];
queue<int> q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m; cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int f, s; cin >> f >> s;
		indegree[s]++;
		v[f].push_back(s);
	}

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			q.push(i);

	while (!q.empty()) {
		int cur = q.front();
		cout << cur << ' ';
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) 
			if (--indegree[v[cur][i]] == 0)
				q.push(v[cur][i]);
	}
	return 0;
}