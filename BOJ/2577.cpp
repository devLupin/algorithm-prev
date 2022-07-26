#include <stdio.h>

int main(void) {
	int arr[10] = { 0 };
	int A, B, C;
	int i;

	int quotient, remainder;

	scanf("%d %d %d", &A, &B, &C);
	quotient = A * B * C;

	while (quotient > 0) {
		remainder = quotient % 10;
		quotient /= 10;

		arr[remainder]++;
	}

	for (i = 0; i < 10; i++)
		printf("%d \n", arr[i]);

	return 0;
}