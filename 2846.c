#include <stdio.h>

int cal(int a, int b) {
	if (a > b)
		return a - b;

	return b - a;
}

int main(void) {
	int arr[1000] = { 0 };

	int src, dest, cur_distance, distance;
	int cur_start, cur_end = 1;
	int sz, i;

	scanf("%d", &sz);

	for (i = 0; i < sz; i++)
		scanf("%d", &arr[i]);

	cur_start = cur_end = 0; distance = -1;
	while (cur_end < sz) {
		if (arr[cur_start] >= arr[cur_end]) {
			cur_start++;
			cur_end = cur_start + 1;
		}
		
		while (arr[cur_end] < arr[cur_end + 1] && cur_end < sz)
			cur_end++;

		cur_distance = arr[cur_end] - arr[cur_start];

		printf("\n\n%d - %d = %d\n\n", arr[cur_end], arr[cur_start, arr[cur_distance]]);
		
		if (distance < cur_distance)
			distance = cur_distance;
	}

	if (distance < 0)
		printf("0 \n");
	else
		printf("%d \n", distance);

	return 0;
}