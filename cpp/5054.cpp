#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int Testcase;
	cin >> Testcase;

	int arr[21];

	for (int T = 0; T < Testcase; T++) {
		int n,result = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < n-1; i++) {
			result += arr[i + 1] - arr[i];
		}
		cout << 2*result << endl;
	}
}