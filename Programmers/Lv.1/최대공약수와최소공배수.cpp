#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

vector<int> solution(int n, int m)
{
    int a = gcd(n, m);
    return {a, n * m / a};
}