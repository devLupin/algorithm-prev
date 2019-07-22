#include<iostream>
#include<cstring>
using namespace std;

int dp[41];

int fibo(int n) {
	if (n <= 1)
		return dp[n];
	else if (dp[n] > 0)
		return dp[n];
	return dp[n] = fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC; cin >> TC;
	for (int i = 0; i < TC; i++) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1, dp[1] = 1;

		int temp;	cin >> temp;

		if (temp == 0) {
			cout << 1 << ' ' << 0 << endl;
			continue;
		}
		else if (temp == 1) {
			cout << 0 << ' ' << 1 << endl;
			continue;
		}

		fibo(temp);
		cout << dp[temp-2] << ' ' << dp[temp-1] << endl;
	}
	return 0;
}