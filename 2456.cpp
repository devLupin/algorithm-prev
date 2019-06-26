#include <iostream>
using namespace std;
#define SCORE	0
#define TOP		1
#define MID		2
int main(void)
{
	int score_top_mid[3][3] = { 0, };
	char arr[1000][3] = { 0, };
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++){
			cin >> arr[i][j];
			if (arr[i][j] == '3')
				score_top_mid[j][TOP]++;
			if (arr[i][j] == '2')
				score_top_mid[j][MID]++;
			score_top_mid[j][SCORE] += arr[i][j] - 48;
		}
	}

	if (score_top_mid[0][SCORE] > score_top_mid[1][SCORE] && 
		score_top_mid[0][SCORE] > score_top_mid[2][SCORE])
		cout << "1 " << score_top_mid[0][SCORE];
	else if(score_top_mid[1][SCORE] > score_top_mid[0][SCORE] &&
		score_top_mid[1][SCORE] > score_top_mid[2][SCORE])
		cout << "2 " << score_top_mid[1][SCORE];
	else if (score_top_mid[2][SCORE] > score_top_mid[0][SCORE] &&
		score_top_mid[2][SCORE] > score_top_mid[1][SCORE])
		cout << "3 " << score_top_mid[2][SCORE];

	else if(score_top_mid[0][SCORE] == score_top_mid[1][SCORE] ||
		score_top_mid[0][SCORE] == score_top_mid[2][SCORE] || 
		score_top_mid[1][SCORE] == score_top_mid[2][SCORE]){

		if(score_top_mid[0][TOP] > score_top_mid[1][TOP] && 
			score_top_mid[0][TOP] > score_top_mid[2][TOP])
			cout << "1 " << score_top_mid[0][SCORE];
		else if (score_top_mid[1][TOP] > score_top_mid[0][TOP] &&
			score_top_mid[1][TOP] > score_top_mid[2][TOP])
			cout << "2 " << score_top_mid[1][SCORE];
		else if (score_top_mid[2][TOP] > score_top_mid[0][TOP] &&
			score_top_mid[2][TOP] > score_top_mid[1][TOP])
			cout << "3 " << score_top_mid[2][SCORE];

		else {
			if (score_top_mid[0][MID] > score_top_mid[1][MID] &&
				score_top_mid[0][MID] > score_top_mid[2][MID])
				cout << "1 " << score_top_mid[0][SCORE];
			else if (score_top_mid[1][MID] > score_top_mid[0][MID] &&
				score_top_mid[1][MID] > score_top_mid[2][MID])
				cout << "2 " << score_top_mid[1][SCORE];
			else if (score_top_mid[2][MID] > score_top_mid[0][MID] &&
				score_top_mid[2][MID] > score_top_mid[1][MID])
				cout << "3 " << score_top_mid[2][SCORE];

			else {
				cout << "0 " << score_top_mid[0][SCORE];
			}
		}
	}
	
	return 0;
}