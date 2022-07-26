#include<iostream>
using namespace std;
int DP[1000001] = { 0, };

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	DP[1] = 1;
	DP[2] = 2;

	int n; cin >> n;
	for (int i = 3; i <= n; i++)
		DP[i] = (DP[i - 1] % 15746 + DP[i - 2] % 15746) % 15746;

	cout << DP[n];
	return 0;
}