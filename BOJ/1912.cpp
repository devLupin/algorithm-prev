#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int DP[100001] = { 0, };
	int cost[100001] = { 0, };
	int result = -1001;

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		DP[i] = max(DP[i - 1] + cost[i], cost[i]);
		result = max(result, DP[i]);
	}
	
	cout << result << endl;
	return 0;
}