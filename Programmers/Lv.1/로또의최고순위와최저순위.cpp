#include <string>
#include <vector>

#include <iostream>
#define endl '\n';

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> score = {6, 6, 5, 4, 3, 2, 1};

    bool visited[46] = {
        false,
    };
    for (auto it = win_nums.begin(); it != win_nums.end(); it++)
        visited[*it] = true;

    vector<int> same;
    int num_zeros = 0;

    for (auto it = lottos.begin(); it != lottos.end(); it++)
    {
        if ((*it) == 0)
            num_zeros++;
        else if (visited[(*it)])
            same.push_back(*it);
    }

    vector<int> answer = {score[same.size() + num_zeros], score[same.size()]};

    return answer;
}

int main(void)
{
    vector<int> lottos = {0, 0, 0, 0, 0, 0};
    vector<int> win_nums = {20, 9, 3, 45, 4, 35};

    auto result = solution(lottos, win_nums);
    for (auto it = result.begin(); it != result.end(); it++)
        cout << (*it) << ' ';
    cout << endl;
}