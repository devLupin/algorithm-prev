#include <iostream>
using namespace std;

void sort(int* arr, int sz) {
	for (int i = 0; i < sz - 1; i++) {
		for (int j = i + 1; j < sz; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(void) {
	int N;
	int* arr = NULL;
	cin >> N;
	arr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, N);

	for (int i = 0; i < N; i++)
		cout << arr[i] << endl;

	return 0;
}