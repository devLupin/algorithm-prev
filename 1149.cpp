#include<iostream>
#include<algorithm>
using namespace std;

int DP[1001][3];
int cost[1001][3];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++)
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	
	for (int i = 1; i <= tc; i++) {
		DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + cost[i][0];
		DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + cost[i][1];
		DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + cost[i][2];
	}
	
	cout << min(min(DP[tc][0], DP[tc][1]), DP[tc][2]);
	return 0;
}