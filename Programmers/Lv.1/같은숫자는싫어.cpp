#include <vector>
#include <iostream>
#include <queue>

#define endl '\n'

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    queue<int> q;

    for(auto it = arr.begin(); it != arr.end(); it++)
        q.push((*it));

    int start = q.front();
    q.pop();
    answer.push_back(start);

    while(!q.empty()) {
        int cur = q.front();
        if(start == cur) q.pop();
        else {
            start = cur;
            answer.push_back(start);
            q.pop();
        }
    }

    return answer;
}

int main(void) {
    vector<int> arr = {4, 4, 4, 3, 3};
    vector<int> answer = solution(arr);

    for(auto it = answer.begin(); it != answer.end(); it++) {
        cout << (*it) << ' ';
    }

    return 0;
}