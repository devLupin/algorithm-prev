#include <iostream>
using namespace std;
int main(void)
{
	char arr[10][10] = { NULL };
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = M-1; j >= 0; j--) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}