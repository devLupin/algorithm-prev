#include <cmath>

using namespace std;

long long solution(long long n)
{
    long long a = sqrt(n);
    return (a * a == n) ? ((a + 1) * (a + 1)) : -1;
}