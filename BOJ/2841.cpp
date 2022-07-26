#include <stack>
#include <iostream>
using namespace std;
int main(void) 
{
	stack<int>* ps = new stack<int>[6];
	int result = 0;
	int N, P, line, pret;
	cin >> N >> P;
	
	for (int i = 0; i < 6; i++)
		ps[i].push(0);

	for (int i = 0; i < N; i++) {
		cin >> line >> pret;
		
		while (ps[line-1].top() > pret) {
			ps[line-1].pop();
			result++;
		}

		if (ps[line - 1].top() != pret) {
			ps[line - 1].push(pret);
			result++;
		}
	}

	cout << result;

	return 0;
}