#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n)
{
    priority_queue<int, vector<int>, less<int>> pq;

    string a = to_string(n);
    for (int i = 0; i < a.size(); i++)
        pq.push(a[i] - '0');

    string ret = "";
    while (!pq.empty())
    {
        ret += pq.top() + '0';
        pq.pop();
    }

    return stoll(ret);
}

long long solution2(long long n)
{
    long long answer = 0;

    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);

    return answer;
}