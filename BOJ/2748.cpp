#include<iostream>
using namespace std;

unsigned long long DP[91] = { 0, };

unsigned long long fibo(int n) {
	if (n == 0)
		return DP[0];
	else if (n == 1)
		return DP[1];
	else {
		if (DP[n] > 0)
			return DP[n];
		else {
			DP[n] = fibo(n - 1) + fibo(n - 2);
			return DP[n];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	DP[0] = 0;
	DP[1] = 1;

	int n; cin >> n;
	cout << fibo(n);
	return 0;
}