#include<iostream>
#include<deque>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int tc; cin >> tc;
	while (tc--) {
		deque<int> dq;

		string oper, set;
		int n;
		cin >> oper >> n >> set;

		bool none = false;
		string temp = "";
		for (auto i = 0; i < set.size(); i++) {
			char cur = set[i];
			if (i == set.size() - 1) {
				if (!temp.compare(""))
					none = true;
				
				else
					dq.push_back(atoi(temp.c_str()));
				
				continue;
			}
			if (cur == '[' || cur == ']')
				continue;
			if (cur == ',') {
				dq.push_back(atoi(temp.c_str()));
				temp = "";
				continue;
			}
			temp += cur;
		}

		bool reverse = false;
		bool ok = true;
		for (int i = 0; i < oper.size(); i++) {
			if (oper[i] == 'R')
				reverse = !reverse;
			else {
				if (dq.empty()) {
					ok = false;
					break;
				}

				if (!reverse)
					dq.pop_front();
				else
					dq.pop_back();
			}
		}
		if (!ok)
			cout << "error" << '\n';
		else {
			if (none)
				while (!dq.empty())
					dq.pop_front();

			cout << '[';
			if (!reverse) {
				while (!dq.empty()) {
					if (dq.size() == 1)
						cout << dq.front();
					else
						cout << dq.front() << ',';

					dq.pop_front();
				}
			}
			if (reverse) {
				while (!dq.empty()) {
					if (dq.size() == 1)
						cout << dq.back();
					else
						cout << dq.back() << ',';

					dq.pop_back();
				}
			}
			cout << ']' << '\n';
		}
	}
	return 0;
}