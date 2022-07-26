#include <stdio.h>

void sort(int arr[], int sz) {
	int i, j;
	for (i = 0; i < sz - 1; i++) {
		for (j = i+1; j < sz; j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(void) {
	int arr[5] = { 0 };
	int i;
	int sum = 0;
	
	for (i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	sort(arr, 5);
	printf("%d \n", sum/5);
	printf("%d", arr[2]);

	return 0;
}