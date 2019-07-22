#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cost[10001] = { 0, };
	int DP[10001] = { 0, };
	int result = 0;

	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> cost[i];

	DP[1] = cost[1];
	if (n > 1)
		DP[2] = cost[1] + cost[2];
	if (n > 2)
		for (int i = 3; i <= n; i++)
			DP[i] = max(max(DP[i - 3] + cost[i] + cost[i - 1], DP[i - 2] + cost[i]), DP[i - 1]);


	cout << DP[n];
	return 0;
}