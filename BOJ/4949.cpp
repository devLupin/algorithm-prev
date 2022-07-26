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

	while (true) {
		string str; getline(cin, str);
		if (str == ".")
			break;

		Stack<char> s;
		bool check1 = true, check2 = true;
		for (int i = 0; i <= str.size(); i++) {
			if (str[i] == '[' || str[i] == '(')
				s.push(str[i]);
			else if (str[i] == ']') {
				if (s.empty()) {
					check1 = false;
					break;
				}

				char temp = s.top();
				if (temp == '[')
					s.pop();
				else {
					check1 = false;
					break;
				}
			}
			else if (str[i] == ')') {
				if (s.empty()) {
					check2 = false;
					break;
				}

				char temp = s.top();
				if (temp == '(')
					s.pop();
				else {
					check2 = false;
					break;
				}
			}
		}
		if (s.empty() && check1 && check2)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
	return 0;
}