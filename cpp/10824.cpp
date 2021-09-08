#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B, C, D, N1, N2;
	long long n1, n2;
	cin >> A >> B >> C >> D;
	N1 = A + B, N2 = C + D;

	n1 = stoll(N1);
	n2 = stoll(N2);

	cout << n1 + n2;
}