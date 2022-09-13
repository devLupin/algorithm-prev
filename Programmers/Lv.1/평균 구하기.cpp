#include <vector>

using namespace std;

double solution(vector<int> arr)
{
    long long sum = 0;
    for (int i = 0; i < arr.size(); i++)
        sum += arr[i];

    return (double)sum / arr.size();
}