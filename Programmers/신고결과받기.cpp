#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    vector<int> answer(id_list.size(), 0);
    map<string, int> id_idx_map;
    map<string, set<string>> report_map;

    for (int i = 0; i < id_list.size(); i++)
        id_idx_map[id_list[i]] = i;

    for (auto rep : report)
    {
        stringstream ss(rep);
        string from, to;
        ss >> from >> to;

        report_map[to].insert(from);
    }

    for (auto it : report_map)
    {
        if (it.second.size() >= k)
            for (auto in_it : it.second)
                answer[id_idx_map[in_it]]++;
    }
    
    return answer;
}

int main(void) {
    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k = 2;

    vector<int> ret = solution(id_list, report, k);
    for(auto it = ret.begin(); it != ret.end(); it++)
        cout << (*it) << ' ';

    return 0;
}