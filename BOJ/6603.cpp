#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;

int arr[14] = { 0, };
int temp[14] = { 0, };

void dfs(int start, int depth, int tc) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++)
			cout << temp[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < tc; i++) {
		temp[depth] = arr[i];
		dfs(i + 1, depth + 1, tc);
	}
	return;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		int tc;		cin >> tc;
		if (tc == 0)
			break;

		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < tc; i++)
			cin >> arr[i];

		dfs(0, 0, tc);
		cout << '\n';
	}
	return 0;
}