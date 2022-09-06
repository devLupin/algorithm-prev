#include <iostream>
#include <string>
#include <vector>
#include <numeric>  // for accumulate
#define endl '\n';

using namespace std;

int solution(vector<int> numbers)
{
    int answer = 0;
    bool visited[10] = {false,};

    for (auto it = numbers.begin(); it != numbers.end(); it++)
        visited[*it] = true;

    for (int i = 0; i < 10; i++)
        if (!visited[i])
            answer += i;

    return answer;
}

int solution2(vector<int> numbers) 
{
    return 45 - accumulate(numbers.begin(), numbers.end(), 0);
}

int main(void)
{
    vector<int> numbers = {1, 2, 3, 4, 6, 7, 8, 0};
    cout << solution(numbers) << endl;
    return 0;
}