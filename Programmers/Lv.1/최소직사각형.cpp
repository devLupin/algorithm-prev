#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define endl '\n';

using namespace std;

// my code
int solution1(vector<vector<int>> sizes)
{
    int ret1 = 0x3f3f3f;
    int ret2 = 0x3f3f3f;

    set<int> s;
    for (int i = 0; i < sizes.size(); i++)
    {
        s.insert(sizes[i][0]);
        s.insert(sizes[i][1]);
    }

    if (s.size() == 1)
    {
        return (*s.begin()) * (*s.begin());
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {
        for (auto in_it = s.begin(); in_it != s.end(); in_it++)
        {
            int first = (*it);
            int second = (*in_it);

            if (first == second)
                continue;

            bool chk = false;
            for (int i = 0; i < sizes.size(); i++)
            {
                if ((first >= sizes[i][0] && second >= sizes[i][1]) ||
                    (second >= sizes[i][0] && first >= sizes[i][1]))
                    chk = true;

                else
                {
                    chk = false;
                    break;
                }
            }
            if (chk)
            {
                if (ret1 * ret2 > first * second)
                {
                    ret1 = first;
                    ret2 = second;
                }
            }
        }
    }

    return ret1 * ret2;
}

// best code
int solution2(vector<vector<int>> sizes)
{
    int answer = 0;

    int w = 0, h = 0;
    for (int i = 0; i < sizes.size(); i++)
    {
        w = max(w, min(sizes[i][0], sizes[i][1]));
        h = max(h, max(sizes[i][0], sizes[i][1]));
    }
    answer = w * h;

    return answer;
}

int main(void)
{
    vector<vector<int>> sizes = {
        {60, 50},
        {30, 70},
        {60, 30},
        {80, 40}};

    cout << solution1(sizes) << endl;
    cout << solution2(sizes) << endl;

    return 0;
}