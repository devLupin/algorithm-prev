#include <string>
#include <vector>

using namespace std;

string solution(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
        if (v[i] == "Kim")
            return "김서방은 " + to_string(i) + "에 있다";
}