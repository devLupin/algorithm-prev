#include<iostream>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unsigned long long DP[101] = { 0, };
	int result[50] = { 0, };

	DP[1] = 1;
	DP[2] = 1;
	DP[3] = 1;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int temp; cin >> temp;
		for (int j = 4; j <= temp; j++) {
			if (DP[j] > 0)
				continue;
			DP[j] = DP[j - 3] + DP[j - 2];
		}
		cout << DP[temp] << endl;
	}
	return 0;
}