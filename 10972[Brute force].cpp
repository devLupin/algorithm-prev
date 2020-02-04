#include <iostream>
#include <algorithm>
using namespace std;

int arr[10001] = { 0, };

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int dest = n - 1;
	for (int i = n - 1; i >= 1; i--) {
		if (arr[i - 1] < arr[i]) {
			dest = i - 1;
			break;
		}
	}
	
	if (dest == n - 1) {
		cout << -1;
		return 0;
	}

	for(int i=n-1; i > dest; i--)
		if (arr[dest] < arr[i]) {
			int temp = arr[dest];
			arr[dest] = arr[i];
			arr[i] = temp;

			break;
		}

	for(int i=dest + 1; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}