#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int DP[501][501] = { 0, }; int result = 0;
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> DP[i][j];

			if (j == 1)
				DP[i][j] += DP[i - 1][j];
			else if (j == i)
				DP[i][j] += DP[i - 1][j - 1];
			else
				DP[i][j] += (max(DP[i - 1][j], DP[i - 1][j - 1]));

			if (result < DP[i][j])
				result = DP[i][j];
		}
	}
	
	cout << result;
	return 0;
}