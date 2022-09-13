#include <vector>
#include <queue>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> pqi;

vector<int> solution(vector<int> arr, int div)
{
    pqi pq;
    for (int i = 0; i < arr.size(); i++)
        if (!(arr[i] % div))
            pq.push(arr[i]);
    vector<int> ret;
    while (!pq.empty())
    {
        ret.push_back(pq.top());
        pq.pop();
    }
    return (ret.empty()) ? vector<int>(1, -1) : ret;
}