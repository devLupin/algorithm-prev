#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Stack {
	int numOfStack;
	int pos;
	int arr[100000];
public:
	Stack() : numOfStack(0), pos(-1)
	{
		memset(arr, 0, sizeof(arr));
	}


	void push(int x) {
		arr[++pos] = x;
		numOfStack++;
	}
	void pop(void) {
		if (empty())
			cout << -1 << '\n';
		else {
			pos--;
			numOfStack--;
		}

	}
	int size(void)const {
		return numOfStack;
	}
	bool empty(void) const {
		if (numOfStack < 1)
			return true;
		else
			return false;
	}
	int top(void) const {
		if (empty())
			cout << -1 << '\n';
		else
			return arr[pos];
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack s;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int temp; cin >> temp;

		if (temp == 0)
			s.pop();
		else
			s.push(temp);
	}
	int ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	cout << ans;
	return 0;
}