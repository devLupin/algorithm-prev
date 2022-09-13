#include <string>

using namespace std;
int solution(int n)
{
    string a = to_string(n);
    int ret = 0;

    for (int i = 0; i < a.size(); i++)
        ret += a[i] - '0';

    return ret;
}