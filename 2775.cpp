#include<iostream>
#define endl '\n'
using namespace std;

// x - 층, y - 호
int arr[15][15];

int main() {

	for (int j = 1; j < 15; j++) {
		arr[0][j] = j;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			// i층 j호에 들어갈 사람 수 계산
			for (int k = 1; k <= j; k++) 
				arr[i][j] += arr[i-1][k];
		}
	}

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int k, n;
		cin >> k >> n;
		cout << arr[k][n] << endl;
	}

	//// 출력
	//for (int i = 0; i < 15; i++) {
	//	for (int j = 1; j < 15; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << endl;
	//}
}