#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;
	vector<int> v(n), ans(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	stack<int> s; s.push(1000001);
	for (int i = n - 1; i >= 0; i--) {
		while (s.top() <= v[i])
			s.pop();
		if (s.top() > 1000000)
			ans[i] = -1;
		else
			ans[i] = s.top();
		s.push(v[i]);
	}

	for (auto i : ans) cout << i << " ";
	return 0;
}