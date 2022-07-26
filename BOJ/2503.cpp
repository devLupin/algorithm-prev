#include <iostream>
#define		BIT	48

using namespace std;

typedef struct baseballList{
	char answer[3];
	int strike, ball;
}bList;

int main(void) 
{
	int N;
	int result = 0;
	
	cin >> N;
	bList* list = new bList[N];
	for (int i = 0; i < N; i++) {
		cin >> list[i].answer >> list[i].strike >> list[i].ball;
	}

	for (int i = 123; i <= 987; i++) {
		bool ok = false;

		char arr[3] = { 0, };
		arr[0] = i / 100 + BIT;
		arr[1] = (i % 100) / 10 + BIT;
		arr[2] = i % 10 + BIT;

		if (arr[2] == '0' || arr[1] == '0') // 10, 1의 자리 0인 경우
			continue;
		
		// 같은 숫자가 하나 이상 있을 경우
		if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
			continue;

		for (int j = 0; j < N; j++) {
			int sCnt = 0;
			int bCnt = 0;
			bool check[3] = { false, };

			for (int k = 0; k < 3; k++) {
				if (list[j].answer[k] == arr[k])
					sCnt++;
			}

			for (int l = 0; l < 3; l++) {
				for (int m = 0; m < 3; m++) {
					if (m == l)
						continue;
					if (list[j].answer[l] == arr[m])
						bCnt++;
				}
			}

			if (list[j].strike != sCnt || list[j].ball != bCnt) {
				ok = false;
				break;
			}
			else
				ok = true;
		}
		if (ok)
			result++;
	}

	cout << result;

	return 0;
}