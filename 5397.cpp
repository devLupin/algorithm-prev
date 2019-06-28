#include<iostream>
#include<string>
#include <list>
#include <vector>
using namespace std;
int main(void)
{
	vector<string> v;

	list<char> s;
	list<char> d;

	int N;
	cin >> N;

	v.reserve(N);
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		int traveler = 0;
		while (traveler < v[i].size()) {
			switch (v[i].at(traveler)) {
			case '<':
				if (s.empty() || traveler == 0) {
					traveler++;
					break;
				}
				d.push_back(s.back());
				s.pop_back();
				traveler++;
				break;
			case '>':
				if (d.empty() || traveler > v[i].size() - 1) {
					traveler++;
					break;
				}
				s.push_back(d.back());
				d.pop_back();
				traveler++;
				break;
			case '-':
				if (s.empty() || traveler == 0) {
					traveler++;
					break;
				}
				s.pop_back();
				traveler++;
				break;
			default:
				s.push_back(v[i].at(traveler));
				traveler++;
			}
		}
		while (!d.empty()) {
			s.push_back(d.back());
			d.pop_back();
		}
		while (!s.empty()) {
			cout << s.front();
			s.pop_front();
		}
		cout << endl;
	}

	return 0;
}