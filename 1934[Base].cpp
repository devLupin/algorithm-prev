#include <iostream>

using namespace std;

int getGCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return getGCD(b, a % b);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b, T; cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> a >> b;
        cout << a * b / getGCD(a, b) << '\n';
    }
}