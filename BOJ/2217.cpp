#include<iostream>
#include<algorithm>
using namespace std;

int w[100000] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> w[i];

	sort(w, w + n, greater<int>());
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < w[i] * (i + 1))
			ans = w[i] * (i + 1);
	}
	cout << ans;
	return 0;
}