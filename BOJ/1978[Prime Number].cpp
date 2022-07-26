#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int arr[1001] = { 0, };
	int result = 0;

	int n; cin >> n;
	for (int i = 0; i < 1001; i++)
		arr[i] = i;

	for (int i = 1; i < 1001; i++) {
		if (i == 1 || i == 2 || i == 3 || i == 5 || i == 7 || i == 11 ||
			i == 13 || i == 17 || i == 19 || i == 23 || i == 29 || i == 31)
			continue;
		if (arr[i] % 2 == 0 || arr[i] % 3 == 0 || arr[i] % 5 == 0 || arr[i] % 7 == 0 || arr[i] % 11 == 0 ||
			arr[i] % 13 == 0 || arr[i] % 17 == 0 || arr[i] % 19 == 0 || arr[i] % 23 == 0 || arr[i] % 29 == 0 || arr[i] % 31 == 0)
			arr[i] = -1;
	}
	arr[1] = -1;

	for (int i = 0; i < n; i++) {
		int temp; cin >> temp;
		
		if (arr[temp] == -1) continue;
		else result++;
	}

	cout << result;
}