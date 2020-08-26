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

	sort(arr, arr + n); // permutation�� �̿��ϱ� ���ؼ��� ������ ��������

	do {
		temp = 0; // �ش� ������ ���ս� ����� �ӽ÷� ��� ����
		for (i = 0; i < n - 1; i++) {
			temp += abs(arr[i] - arr[i + 1]); // |A[0] - A[1]| + ...
		}
		sum = max(sum, temp); // �ش������ ���ս��� ����� ���� sum���� ũ�� sum�� ����
	} while (next_permutation(arr, arr + n)); // ���� ������ ���� �� ���� �ݺ��Ͽ� �ִ��� ã��

	cout << sum << "\n";
}