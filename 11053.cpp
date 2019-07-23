#include<iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int ans = 0;

	int cache[1001] = { 0, };
	int DP[1001] = { 0, };
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cache[i];

	for (int i = 1; i <= n; i++) {
		DP[i] = 1;
		for (int j = 1; j < i; j++) {
			if (cache[i] > cache[j] && DP[j]+1 > DP[i]) {
				DP[i] = DP[j] + 1;
			}
		}
		ans = (DP[i] > ans) ? DP[i] : ans;
	}

	cout << ans;
	return 0;
}