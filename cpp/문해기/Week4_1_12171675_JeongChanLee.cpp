#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

void solve() {
	int isInc = false;
	int A, B, x, y;
	cin >> A >> B >> x >> y;
	int gcd = abs(A - B);
	int decA = A / gcd;
	int incA = decA + 1;
	int answer = min((A - decA * gcd) * y, (incA * gcd - A) * x);
	cout << gcd << " " << answer << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}