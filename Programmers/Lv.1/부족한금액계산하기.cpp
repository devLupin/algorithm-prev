using namespace std;

typedef long long LL;
LL solution(int price, int money, int count)
{
    LL answer = money;
    for (int i = 1; i <= count; i++)
        answer -= (price * i);

    return (answer > 0) ? 0 : answer * (-1);
}