#include<iostream>
#include<algorithm>
using namespace std;

int s_DP[1001] = { 0, }, l_DP[1001] = { 0, };
int c[1001] = { 0, };
int n, ret = 0;

void find(void) {
	for (int i = 1; i <= n; i++) {
		l_DP[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (c[i] > c[j] && l_DP[i] < l_DP[j] + 1)
				l_DP[i] = l_DP[j] + 1;
		}
	}
	for (int i = n; i >= 1; i--) {
		s_DP[i] = 1;
		for (int j = n; j >= i; j--) {
			if (c[i] > c[j] && s_DP[i] < s_DP[j] + 1)
				s_DP[i] = s_DP[j] + 1;
		}
	}
}

void result(void) {
	find();

	for (int i = 1; i <= n; i++) {
		ret = max(ret, l_DP[i] + s_DP[i] - 1);
	}
	cout << ret;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i];

	result();

	return 0;
}