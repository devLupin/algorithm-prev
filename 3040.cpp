#include <iostream>
using namespace std;

void find(const int arr[])
{
	int sum = 0;
	int result[7] = { 0, };
	int first = 0, second = 1;
	int rIdx = 0;

	while (first < 7) {
		if (sum == 100)
			break;

		sum = rIdx = 0;
		for (int i = 0; i < 9 && sum < 101; i++) {
			if (i == first || i == second)
				continue;
			sum += arr[i];
			result[rIdx++] = arr[i];
		}

		second++;
		if (second > 8) {
			first++;
			second = first + 1;
		}
	}

	for (int i = 0; i < 7; i++)
		cout << result[i] << endl;

	return;
}

int main(void)
{
	int arr[9] = { 0, };
	for (int i = 0; i < 9; ++i) {
		cin >> arr[i];

		if (arr[i] < 1 || arr[i] > 99) {
			--i;
			continue;
		}
	}
	find(arr);
	return 0;
}