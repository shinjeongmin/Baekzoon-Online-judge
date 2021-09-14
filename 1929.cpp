#include<iostream>
#include<algorithm>
using namespace std;

int arr[1000001];

int main() {
	fill_n(arr, sizeof(arr) / sizeof(arr[0]), 1);
	int M, N;
	arr[0] = 0, arr[1] = 0;

	cin >> M >> N;
	int maxMeasure = N / 2;
	for (int i = 2; i <= maxMeasure; i++) {
		int j;
		for (j = 2; i * j <= N; j++) {
			arr[i * j] = 0;
		}
	}

	//print
	for (int i = M; i <= N; i++) {
		if (arr[i] == 1)
			cout << i << "\n";
	}
}