#include <iostream>
using namespace std;
int main(void)
{
	long long N = 0;
	cin >> N;

	if ((N - 1) % 5 + 1 == 2 || (N - 1) % 5 + 1 == 5)
		cout << "CY";
	else
		cout << "SK";

	return 0;
}