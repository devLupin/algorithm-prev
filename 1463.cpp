#include<iostream>
#include<cstring>
#define MIN(A,B)	(A) < (B) ? (A) : (B)
using namespace std;
const int __max = 98765432;
int arr[1000001];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(arr, __max, sizeof(arr));

	int n; cin >> n;
	arr[1] = 0;
	for (int i = 2; i <= n; i++) {
		int div2 = __max, div3 = __max, minus1 = __max;

		if (i%2 == 0)
			div2 = arr[i / 2]+1;
		if (i%3 == 0)
			div3 = arr[i / 3]+1;

		minus1 = arr[i - 1]+1;
		
		arr[i] = MIN(div2, MIN(div3, minus1));
	}

	cout << arr[n];
}