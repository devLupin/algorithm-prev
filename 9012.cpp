#include<iostream>
#include<cstring>
#include<string>
using namespace std;

template<class T>
class Stack {
	T numOfStack;
	T pos;
	T arr[100000];
public:
	Stack() : numOfStack(0), pos(-1)
	{
		memset(arr, 0, sizeof(arr));
	}


	void push(T x) {
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
	T size(void)const {
		return numOfStack;
	}
	bool empty(void) const {
		if (numOfStack < 1)
			return true;
		else
			return false;
	}
	T top(void) const {
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

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		string temp = ""; cin >> temp;
		Stack<char> s;
		bool control = true;
		for (int j = 0; j <= temp.size(); j++) {
			if (temp[j] == '(')
				s.push('(');
			else if (temp[j] == ')') {
				if (s.empty()) {
					control = false;
					break;
				}
				s.pop();
			}
		}
		if (s.empty() && control)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}
	return 0;
}