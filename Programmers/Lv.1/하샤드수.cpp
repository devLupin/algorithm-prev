#include <string>

using namespace std;

bool solution(int x)
{
    int div = 0;
    string a = to_string(x);
    for (int i = 0; i < a.length(); i++)
        div += a[i] - '0';

    return !(x % div);
}