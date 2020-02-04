#include <iostream>
using namespace std;

int arr[1000001] = { 0, };

int getGCD(int a, int b)
{
    if (b == 0)
        return a;
    else
        return getGCD(b, a % b);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        long result = 0;
        int n; cin >> n;
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                result += getGCD(arr[i], arr[j]);

        cout << result << '\n';
    }
    return 0;
}