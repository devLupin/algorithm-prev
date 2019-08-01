#include<iostream>
#include<string>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node* prev;
	Node* next;

	Node(int x) : data(x) {
		prev = next = NULL;
	}
};

template<class T>
class Deque {
	Node<T>* front;
	Node<T>* rear;
	int numOfDeque;

public:
	Deque() : numOfDeque(0)
	{
		front = rear = NULL;
	}

	int size() {
		return numOfDeque;
	}
	int empty() {
		return (front == NULL);
	}

	void insert_front(T x) {
		Node<T>* newNode = new Node<T>(x);
		
		if (front == NULL)
			front = rear = newNode;
		else {
			newNode->next = front;
			front->prev = newNode;
			front = newNode;
		}
		numOfDeque++;
	}
	void insert_rear(T x) {
		Node<T>* newNode = new Node<T>(x);

		if (rear == NULL)
			front = rear = newNode;
		else {
			newNode->prev = rear;
			rear->next = newNode;
			rear = newNode;
		}
		numOfDeque++;
	}

	T delete_front() {
		Node<T>* delNode = front;
		int delData;

		if (empty())
			return -1;
		front = front->next;
		if (front == NULL)
			rear = NULL;
		else
			front->prev = NULL;

		numOfDeque--;

		delData = delNode->data;
		delete delNode;
		return delData;
	}
	T delete_rear() {
		Node<T>* delNode = rear;
		int delData;

		if (empty())
			return -1;
		rear = rear->prev;
		if (rear == NULL)
			front = NULL;
		else
			rear->next = NULL;

		numOfDeque--;

		delData = delNode->data;
		delete delNode;
		return delData;
	}

	T _front() {
		if (empty())
			return -1;
		return front->data;
	}
	T _rear() {
		if (empty())
			return -1;
		return rear->data;
	}
};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	Deque<int> dq;

	int tc;  cin >> tc;
	for (int t = 0; t < tc; t++) {
		string opt; cin >> opt;
		int x;
		if (!opt.compare("push_back")) {
			cin >> x;
			dq.insert_rear(x);
		}
		else if (!opt.compare("push_front")) {
			cin >> x;
			dq.insert_front(x);
		}
		else if (!opt.compare("front")) {
			cout << dq._front() << '\n';
		}
		else if (!opt.compare("back")) {
			cout << dq._rear() << '\n';
		}
		else if (!opt.compare("size")) {
			cout << dq.size() << '\n';
		}
		else if (!opt.compare("empty")) {
			cout << dq.empty() << '\n';
		}
		else if (!opt.compare("pop_front")) {
			cout << dq.delete_front() << '\n';
		}
		else if (!opt.compare("pop_back")) {
			cout << dq.delete_rear() << '\n';
		}
	}
	return 0;
}