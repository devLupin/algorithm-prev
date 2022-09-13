#include <string>
#include <vector>

using namespace std;

string solution(string number)
{
    for (int i = 0; i < number.length() - 4; i++)
        number[i] = '*';
    return number;
}