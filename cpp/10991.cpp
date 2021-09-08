#include<iostream>
using namespace std;

void charactor(int n);

int main() {
	int N;

	cin >> N;

	int MaxN = N + N - 1; // 마지막줄에서 여백과 *의 갯수 합.
	for (int i = 1; i <= N; i++){ // 행의 갯수별 반복문

		int odd_of_line = i * 2 - 1; //각 줄에서 *을 시작으로 여백이 포함된 부분의 문자 총 개수.

		for (int j = 0; j < (MaxN - (odd_of_line)) / 2; j++) { // *로 둘러싸인 부분이 나오기 전 여백의 갯수
			cout << " ";
		}
		charactor(odd_of_line);
		cout << endl;
	}
}

void charactor(int n) { // *이 둘러싸고 * 공백한칸으로 이루어진 부분. (* * *)
	for (int i = 1; i <= n; i++)
	{
		if (i % 2 == 0)
			cout << " ";
		else
			cout << "*";
	}
	return;
}