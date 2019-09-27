#include <cstdio>
#include <algorithm>
using namespace std;

const int init = 100001;
int c[101][101] = { 0, };
int n, e;
void floyd() {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
					c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
}

int main(void)
{
	
	scanf("%d %d", &n, &e);
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			c[i][j] = (i == j) ? 0 : init;
	
	
	while (e--) {
		int src, dest, cost; scanf("%d %d %d", &src, &dest, &cost);
		c[src][dest] = (c[src][dest] > cost) ? cost : c[src][dest];
	}

	floyd();
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) 
			printf("%d ", (c[i][j] == init) ? 0 : c[i][j]);
		printf("\n");
	}
}