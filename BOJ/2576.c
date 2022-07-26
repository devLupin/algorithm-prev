#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int arr[7] = { 0 };
	int odd = 0;
	int min = 99;

	int i;

	for (i = 0; i < 7; i++) {
		scanf("%d", &arr[i]);

		if ((arr[i] % 2) > 0) {
			odd += arr[i];
			
			if (arr[i] < min)
				min = arr[i];
		}
	}

	if (odd == 0)
		printf("-1");
	else {
		printf("%d \n", odd);
		printf("%d ", min);
	}

	return 0;
}