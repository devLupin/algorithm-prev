#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget)
{
    int sum = 0;
    int ret = 0;

    sort(d.begin(), d.end(), less<int>());
    
    for (int i = 0; i < d.size(); i++)
    {
        if (sum + d[i] > budget)
            break;

        sum += d[i];
        ret++;
    }

    return ret;
}