#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Queue {
	int first;
	int numOfData;
	int cur;
	int arr[10000];
public:
	Queue() : first(0), numOfData(0), cur(0)
	{
		memset(arr, 0, sizeof(arr));
	}
	void push(int x){
		arr[cur++] = x;
		numOfData++;
	}
	int pop() {
		if (empty())
			return -1;

		int retData = arr[first++];
		numOfData--;

		return retData;
	}
	int size() const {
		return numOfData;
	}
	int empty() const {
		if (numOfData <= 0)
			return 1;
		else
			return 0;
	}
	int front() const {
		if (empty())
			return -1;
		return arr[first];
	}
	int back() const {
		if (empty())
			return -1;
		return arr[cur-1];
	}
};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Queue q;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		string opt; cin >> opt;
		int temp;
		if (opt == "push") {
			cin >> temp;
			q.push(temp);
		}
		else if (opt == "pop")
			cout << q.pop() << '\n';
		else if (opt == "size")
			cout << q.size() << '\n';
		else if (opt == "empty")
			cout << q.empty() << '\n';
		else if (opt == "front")
			cout << q.front() << '\n';
		else
			cout << q.back() << '\n';
	}
	return 0;
}