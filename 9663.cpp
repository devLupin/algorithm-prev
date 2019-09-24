#include<cstdio>
#include<map>
using namespace std;

int N, ans = 0;
int m[15];

bool check(int i)
{
	for (int j = 0; j < i; j++)
		if (m[j] == m[i] || abs(m[i] - m[j]) == (i - j))
			return false;
	return true;
}
void dfs(int i)
{
	if (i == N) {
		ans += 1;
		return;
	}
	for (int j = 0; j < N; j++) {
		m[i] = j;
		if (check(i))
			dfs(i + 1);
	}
}

int main()
{
	scanf("%d", &N);
	dfs(0);
	printf("%d", ans);
	return 0;
}