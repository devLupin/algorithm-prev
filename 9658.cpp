#include <iostream>
using namespace std;

int main(void)
{
	int N;
	bool arr[1005] = { 0, 1, 0, 1 };
	
	for (int i = 5; i < 1000; i++) {
		arr[i] = (arr[i - 1] + arr[i - 3] + arr[i - 4] == 0) ? 1 : 0;
	}

	cin >> N;
	cout << ((arr[N]) ? "CY" : "SK");

	return 0;
}