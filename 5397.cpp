#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(void) 
{
	vector<string> v;

	int N;
	cin >> N;
	
	v.reserve(N);
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	for (int i = 0; i < N; i++) {
		int cursor = 0;
		int traveler = 0;
		string result = "";
		while (traveler < v[i].size()) {
			char temp = v[i].at(traveler);
			
			switch (temp) {
			case '<':
				if (cursor == 0) {
					traveler++;
					break;
				}
				traveler++;
				cursor--;
				break;
			case '>':
				if (cursor >= result.size()) {
					traveler++;
					break;
				}
				traveler++;
				cursor++;
				break;
			case '-':
				if (!result.empty()) {
					string front = result.substr(0, cursor - 1);
					string end = result.substr(cursor);

					result = front;
					result.append(end);
					
					traveler++;
					cursor--;
					
					break;
				}
				traveler++;
				break;
			default:
				string addChar(1, temp);
			
				if (cursor == 0 || cursor == result.size()) {
					result.append(addChar);
					cursor++;
					traveler++;
					break;
				}
				string front = result.substr(0, cursor);
				string end = result.substr(cursor);

				result = front;
				result.append(addChar);
				result.append(end);

				cursor++;
				traveler++;
			}
		}
		cout << result << endl;
	}

	return 0;
}