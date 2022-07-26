#include<iostream>
#define MAX(a, b) ((a) > (b)) ? (a) : (b)
using namespace std;

int stairs[10000] = { 0, };
int dp[10000] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stairs[i];

	dp[0] = stairs[0];
	dp[1] = MAX(stairs[1], stairs[0] + stairs[1]);
	dp[2] = MAX(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (int i = 3; i < n; i++)
		dp[i] = MAX(dp[i - 2] + stairs[i], stairs[i - 1] + stairs[i] + dp[i - 3]);
	
	cout << dp[n - 1];
	return 0;
}