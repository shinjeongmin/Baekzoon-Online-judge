#include<iostream>
using namespace std;
#define endl '\n'

bool AllNumber[1001] = {true,true, }; // 지워진 수는 true
int N; // N보다 작거나 할때 N
int K, eraseCnt, K_Number;
void EraseMultiple(int);

void Eratosthenes() {
	for (int i = 2; i <= N; i++) {
		EraseMultiple(i);
	}
}

void EraseMultiple(int n) {
	/* 
	원래 int i = 1 에서 시작하는게 아닌
	int i = 2 에서 시작해야 소수를 지우지 않고 남길 수 있다.
	*/
	for (int i = 1; i * n <= N; i++) {
		// 아직 지우지 않은 수(false)라면
		if (AllNumber[i * n] == false) {
			AllNumber[i * n] = true;
			eraseCnt++;
			if (eraseCnt == K) {
				K_Number = i * n;;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;

	Eratosthenes();

	//// 범위 내 모든 소수 출력
	//for (int i = 2; i <= N; i++) {
	//	if (!AllNumber[i])
	//		cout << i << endl;
	//}

	cout << K_Number;
}