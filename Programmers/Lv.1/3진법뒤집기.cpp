#include <string>

using namespace std;

string get_reverse_ternary(int n)
{
    string s = "";
    while (n >= 3)
    {
        int remainder = n % 3;
        s += (remainder + '0');
        n /= 3;
    }
    s += (n + '0');
    return s;
}

int solution(int n)
{
    int ret = 0;
    string ternary = get_reverse_ternary(n);
    int mul = 1;
    for (int i = ternary.length() - 1; i >= 0; i--)
    {
        ret += (mul * (ternary[i] - '0'));
        mul *= 3;
    }
    return ret;
}