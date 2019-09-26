#include<cstdio>
#include<cmath>

int main()
{
	int tc; scanf("%d", &tc);
	while (tc--) {
		int a, b, c; scanf("%d %d", &a, &b);
		c = a;
		for (int i = 1; i < b; i++)
			c = c * a % 10;
		printf("%d\n", (c==0)?10:c);
	}
}