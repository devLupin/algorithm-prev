#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	bool chk = true;
	for (int i = 0; i < 8 && chk; i++) {
		for (int j = i + 1; j < 9; j++) {
			int temp = sum;
			temp -= (arr[i] + arr[j]);

			if (temp == 100) {
				arr[i] = -1;
				arr[j] = -1;
				
				chk = false;
				break;
			}
		}
	}

	sort(arr, arr + 9);

	for (int i = 2; i < 9; i++)
		cout << arr[i] << '\n';
	
	return 0;
}