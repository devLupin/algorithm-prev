#include <string>
#include <vector>
#include <map>
#include <iostream>

#define endl '\n'

using namespace std;

string solution(vector<string> survey, vector<int> choices)
{
    string answer = "";

    char type[] = {'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N'};
    int score[] = {-3, -2, -1, 0, 1, 2, 3};

    map<char, int> survey_elem;

    for (int i = 0; i < survey.size(); i++)
    {
        char first = survey[i][0];
        char second = survey[i][1];
        int cur_score = score[choices[i] - 1];
        (cur_score < 0) ? survey_elem[first] += (cur_score * -1) : survey_elem[second] += cur_score;
    }

    for (int i = 0; i < sizeof(type) - 1; i += 2)
    {
        char first = type[i];
        char second = type[i + 1];

        (survey_elem[first] >= survey_elem[second]) ? answer += first : answer += second;
    }

    return answer;
}

int main(void)
{
    vector<string> survey = {"AN", "CF", "MJ", "RT", "NA"};
    vector<int> choices = {5, 3, 2, 7, 5};

    string ret = solution(survey, choices);

    cout << ret << endl;
    return 0;
}