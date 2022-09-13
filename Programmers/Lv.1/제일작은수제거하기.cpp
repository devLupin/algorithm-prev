#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int pos = -1;
    int max = 0x3f3f3f;
    for (int i = 0; i < arr.size(); i++)
        if (max > arr[i])
        {
            pos = i;
            max = arr[i];
        }

    arr.erase(arr.begin() + pos);
    return arr.empty() ? vector<int>(1, -1) : arr;
}