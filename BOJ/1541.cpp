#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 0;

	string str = "";
	cin >> str;

	string temp = "";
	bool sw = false;
	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '-' || str[i] == '+' || str[i] == '\0') {
			if (sw)
				ans -= stoi(temp);
			else
				ans += stoi(temp);
			temp = "";
			if (str[i] == '-')
				sw = true;
			continue;
		}
		temp += str[i];
	}

	cout << ans;

	return 0;
}