#include<iostream>
using namespace std;

int result[11] = { 0, };
int cases[11] = { 0, };
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	result[0] = 0;
	result[1] = 1;
	result[2] = 2;
	result[3] = 4;

	int TC; cin >> TC;
	for (int i = 0; i < TC; i++)
		cin >> cases[i];

	for (int i = 4; i < 11; i++)
		result[i] = result[i - 3] + result[i - 2] + result[i - 1];


	for (int i = 0; i < TC; i++)
		cout << result[cases[i]] << endl;

	return 0;
}