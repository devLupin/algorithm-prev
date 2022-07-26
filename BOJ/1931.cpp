#include<iostream>
#include<algorithm>
using namespace std;

typedef struct confirm {
	int src, dest;
}Confirm;

Confirm c[100001];


bool cmp(const Confirm& a, const Confirm& b) {
	if (a.dest == b.dest) {
		return a.src < b.src;
	}
	else {
		return a.dest < b.dest;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c[i].src >> c[i].dest;

	sort(c, c + n, cmp);		// start, end, sort(userdefine, greater<type>, less<type>)

	int now = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (now <= c[i].src) {
			now = c[i].dest;
			ans++;
		}
	}
	cout << ans;
	return 0;
}