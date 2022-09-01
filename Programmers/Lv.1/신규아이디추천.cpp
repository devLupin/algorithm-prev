#include <vector>
#include <iostream>
#include <string>

using namespace std;

string solution(string new_id)
{
    // phase 1, 2
    for (int i = 0; i < new_id.size(); i++)
    {
        new_id[i] = tolower(new_id[i]);

        if ((new_id[i] >= 'a' && new_id[i] <= 'z') ||
            (new_id[i] >= '0' && new_id[i] <= '9') ||
            (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'))
            continue;
        else
            new_id[i] = ' ';
    }
    new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());

    // phase 3
    int cnt = 1;
    int start = -1;
    vector<pair<int, int>> v;
    for (int i = 0; i < new_id.size(); i++)
    {
        if (start == -1 && new_id[i] == '.')
            start = i;
        else if (start != -1 && new_id[i] == '.')
            cnt++;
        else if (start != -1 && new_id[i] != '.')
        {
            if (cnt >= 2)
                v.push_back(make_pair(start, start + cnt));

            cnt = 1;
            start = -1;
        }
    }
    if (cnt >= 2)
        v.push_back(make_pair(start, start + cnt));

    int change_idx = 0;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        int start = (*it).first;
        int end = (*it).second;

        start -= change_idx;
        end -= change_idx;

        new_id.replace(start, end - start, ".");
        change_idx += (end - start - 1);
    }

    // phase 4
    if (!new_id.empty())
    {
        if (new_id[0] == '.')
            new_id[0] = ' ';
        else if (new_id[new_id.size() - 1] == '.')
            new_id[new_id.size() - 1] = ' ';

        new_id.erase(remove(new_id.begin(), new_id.end(), ' '), new_id.end());
    }
    // phase 5
    if (new_id.empty())
        new_id = "a";

    // phase 6-1
    if (new_id.size() >= 16)
        new_id = new_id.substr(0, 15);

    // phase 6-2
    if (!new_id.empty() && new_id[new_id.size() - 1] == '.')
        new_id = new_id.substr(0, new_id.size() - 1);

    // phase 7
    while (!new_id.empty() && new_id.size() < 3)
        new_id += new_id[new_id.size() - 1];

    return new_id;
}

int main(void)
{
    string new_id = "..1...2.....5..";
    cout << solution(new_id) << endl;
    return 0;
}