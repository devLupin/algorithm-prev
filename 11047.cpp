#include<iostream>
using namespace std;
int coin[10];
int main(void)
{
	int ans = 0;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> coin[i];

	int temp = n-1;
	int copy = k;
	while (copy > 0) {
		while (coin[temp] > copy)
			temp--;
		copy -= coin[temp];
		ans++;
	}
	cout << ans;
	return 0;
}