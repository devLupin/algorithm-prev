#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> num(n);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	sort(num.begin(), num.end());
	for (int i = 0; i < n; i++)
		cout << num[i] << '\n';

	return 0;
}