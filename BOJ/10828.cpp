#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Stack {
	int numOfStack;
	int pos;
	int arr[10000];
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
		if (numOfStack < 1)
			cout << -1 << '\n';
		else {
			cout << arr[pos--] << '\n';
			numOfStack--;
		}

	}
	void size(void)const {
		cout << numOfStack << '\n';
	}
	void empty(void) const {
		if (numOfStack < 1) 
			cout << 1 << endl;
		else 
			cout << 0 << endl;
	}
	void top(void) const {
		if (numOfStack < 1)
			cout << -1 << '\n';
		else
			cout << arr[pos] << '\n';
	}
};

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Stack s;

	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		string temp = "";
		cin >> temp;
		if (temp == "push") {
			int num; cin >> num;
			s.push(num);
		}
		else {
			if (temp == "pop")
				s.pop();
			else if (temp == "size")
				s.size();
			else if (temp == "empty")
				s.empty();
			else
				s.top();
		}
	}

	return 0;
}