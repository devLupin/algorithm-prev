#include <vector>

using namespace std;

int get_num_divisor(int num)
{
    int ret = 1;
    for (int i = 2; i <= num; i++)
        if (!(num % i))
            ret++;
    return ret;
}

int solution(int left, int right)
{
    int answer = 0;
    for (int i = left; i <= right; i++)
        answer += (get_num_divisor(i) & 1) ? i * (-1) : i;
    return answer;
}