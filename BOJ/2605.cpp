#include <iostream>
using namespace std;

int main(void) {
	int arr[100] = { 0, };
	int sz;

	int end_pos, input_pos;
	int input;

	cin >> sz;

	for (int i = 0; i < sz; ++i) {
		end_pos = i;

		cin >> input;

		//���� ���� ��ȣ�� �ڽ��� ó���� �� �������ٴ� ���� ���̴�.
		if (input > sz + 1) {
			--i;
			continue;
		}

		input_pos = end_pos - input;
		for (int j = i; j > input_pos; --j)
			arr[j] = arr[j - 1];

		arr[input_pos] = i + 1;
	}

	for (int i = 0; i < sz; i++)
		cout << arr[i] << " ";

	return 0;
}