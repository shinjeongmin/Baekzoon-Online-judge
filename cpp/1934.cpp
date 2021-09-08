#include<iostream>
#include<algorithm>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int Testcase;
	cin >> Testcase;
	for (int t = 0; t < Testcase; t++)
	{
		int A, B;
		cin >> A >> B;
		int lcd = max(A, B);
		int Max = max(A, B);
		for (int i = lcd; i % A != 0 || i % B != 0; i+=Max) { lcd+=Max; }
		cout << lcd << endl;
	}
}