#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;
int main()
{
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };

	int n = 3;
	int src = 0;

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			if (temp == 0) {
				temp = 9;
			}
			src = src * 10 + temp;
		}
	}

	map<int, int> dest;
	queue<int> q;
	q.push(src);
	dest[src] = 0;

	while (!q.empty())
	{
		int now_num = q.front();
		string now = to_string(now_num);
		q.pop();

		int z = now.find('9');
		int x = z / 3;
		int y = z % 3;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				string next = now;
				swap(next[x * 3 + y], next[nx * 3 + ny]);
				int num = stoi(next);

				if (dest.count(num) == 0)
				{
					dest[num] = dest[now_num] + 1;
					q.push(num);
				}
			}
		}
	}

	
	if (dest.count(123456789) == 0)
		cout << "-1" << "\n";
	else
		cout << dest[123456789] << "\n";

	return 0;
}