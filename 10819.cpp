#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int n, i, sum = 0, temp;
	int arr[8];

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n); // permutation을 이용하기 위해서는 정렬이 전제조건

	do {
		temp = 0; // 해당 순열의 차합식 결과를 임시로 담는 공간
		for (i = 0; i < n - 1; i++) {
			temp += abs(arr[i] - arr[i + 1]); // |A[0] - A[1]| + ...
		}
		sum = max(sum, temp); // 해당순열의 차합식의 결과가 현재 sum보다 크면 sum에 저장
	} while (next_permutation(arr, arr + n)); // 다음 순열이 없을 때 까지 반복하여 최댓값을 찾음

	cout << sum << "\n";
}