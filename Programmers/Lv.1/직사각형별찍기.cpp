#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a = 0, b = 0;
    cin >> a >> b;

    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
            cout << '*';
        cout << '\n';
    }
    return 0;
}