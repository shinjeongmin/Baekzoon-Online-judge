#include<iostream>
using namespace std;
#define endl '\n'

bool AllNumber[1001] = {true,true, }; // ������ ���� true
int N; // N���� �۰ų� �Ҷ� N
int K, eraseCnt, K_Number;
void EraseMultiple(int);

void Eratosthenes() {
	for (int i = 2; i <= N; i++) {
		EraseMultiple(i);
	}
}

void EraseMultiple(int n) {
	/* 
	���� int i = 1 ���� �����ϴ°� �ƴ�
	int i = 2 ���� �����ؾ� �Ҽ��� ������ �ʰ� ���� �� �ִ�.
	*/
	for (int i = 1; i * n <= N; i++) {
		// ���� ������ ���� ��(false)���
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

	//// ���� �� ��� �Ҽ� ���
	//for (int i = 2; i <= N; i++) {
	//	if (!AllNumber[i])
	//		cout << i << endl;
	//}

	cout << K_Number;
}