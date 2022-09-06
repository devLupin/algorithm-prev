#include <vector>
#include <stack>
#include <iostream>
#define endl '\n';

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> bucket;

    for (auto it = moves.begin(); it != moves.end(); it++)
    {
        for (int i = 0; i < board.size(); i++)
        {
            int x = i;
            int y = (*it) - 1;

            if (board[x][y] != 0)
            {
                if (!bucket.empty() && bucket.top() == board[x][y])
                {
                    bucket.pop();
                    answer++;
                }
                else
                    bucket.push(board[x][y]);

                board[x][y] = 0;
                break;
            }
        }
    }

    return answer * 2;
}

int main(void)
{
    vector<vector<int>> board = {
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 3},
        {0, 2, 5, 0, 1},
        {4, 2, 4, 4, 2},
        {3, 5, 1, 3, 1}};
    vector<int> moves = {1, 5, 3, 5, 1, 2, 1, 4};

    cout << solution(board, moves) << endl;

    return 0;
}