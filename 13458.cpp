#include<cstdio>
#include<vector>
#include<climits>
using namespace std;

int arr[1000001];

int main(void)
{
	int n, b, c;
	long long ans = 0;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)scanf("%d", &arr[i]);
	
	scanf("%d %d", &b, &c);
	
	for (int i = 0; i < n; i++) {
		arr[i] -= b; ans++;
		
		if (arr[i] > 0) {
			if (arr[i] % c == 0) 
				ans += (arr[i] / c);
			else 
				ans += (arr[i] / c) + 1;
		}
	}
	printf("%lld", ans);
}