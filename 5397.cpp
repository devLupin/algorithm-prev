/* Don't solve */

#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(void) 
{
	string* result = NULL;
	vector<string> v;
	int N;
	cin >> N;
	
	result = new string[N];
	v.reserve(N);
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		int traveler = 0;
		while (traveler < v[i].size()) {
			char temp = v[i].at(traveler);
			
			switch (temp) {
			case '<':
				if (result[i].size() == 0)
					break;
				traveler--;
				break;
			case '>':
				if (result[i].size() - 1 < traveler)
					break;
				traveler++;
				break;
			case '-':
				if (!result[i].empty()) {
					result[i].erase(traveler, 1);
				}
				traveler++;
				break;
			default:
				string tmp = result[i].substr(traveler);
				result[i] = result[i].substr(0, traveler - 1);
				result[i].append(tmp);

				traveler++;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << result[i] << endl;

	return 0;
}