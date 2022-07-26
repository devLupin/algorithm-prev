//http://sioh59.blogspot.com/2017/01/baekjoon-1010-dynamic-programming.html
#include<cstdio>
#include<cstring>
int n, m, tc, d[31][31];

int bridge(int l, int r)
{
	if (l == r || l == 0)return 1;
	if (d[l][r] != 0)return d[l][r];
	return d[l][r] = bridge(l - 1, r - 1) + bridge(l, r - 1);
}
int main()
{
	scanf("%d", &tc);
	while (tc--) {
		memset(d, 0, sizeof(d));
		int n, m; scanf("%d %d", &n, &m);
		printf("%d\n", bridge(n, m));
	}
}