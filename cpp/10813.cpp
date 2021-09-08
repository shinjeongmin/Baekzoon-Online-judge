#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	int arr[100];
	cin >> N >> M;

	for (int i = 0; i < N; i++){ // 바구니 채우기
		arr[i] = i + 1;
	}

	for (int z = 0; z < M; z++) {
		int i,j;
		cin >> i >> j;
		swap(arr[i - 1], arr[j - 1]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}