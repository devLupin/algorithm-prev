#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>
#include <map>

using namespace std;

map<string, string> m;

void rules()
{
    m["zero"] = "0";
    m["one"] = "1";
    m["two"] = "2";
    m["three"] = "3";
    m["four"] = "4";
    m["five"] = "5";
    m["six"] = "6";
    m["seven"] = "7";
    m["eight"] = "8";
    m["nine"] = "9";
}

int solution1(string s)
{
    rules();

    string ret = "";
    string cur = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
            ret += s[i];
        else
        {
            cur += s[i];
            if (m[cur] != "")
            {
                ret += m[cur];
                cur = "";
            }
        }
    }

    return stoi(ret);
}

vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

int solution2(string s) {
    int answer = 0;
    regex r;
    for(int i = 0; i < numbers.size(); i++) {
        r = numbers[i];
        s = regex_replace(s, r, to_string(i));
        // s = regex_replace(s, regex("zero"), "0");
    }
    answer = stoi(s);
    return answer;
}


int main(void)
{
    string s = "one4seveneight";
    cout << solution1(s) << endl;
    cout << solution2(s) << endl;
    return 0;
}