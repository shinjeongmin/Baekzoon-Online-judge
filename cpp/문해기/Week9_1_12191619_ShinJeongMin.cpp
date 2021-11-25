#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int T;
long long X, N, M;
pair<long long, long long> GeoSeries(long long x, long long n);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> X >> N >> M;

		pair<long long, long long> Answer = GeoSeries(X, N);

		cout << Answer.second << "\n";
	}
}

pair<long long, long long> GeoSeries(long long x, long long n) {
	if (n==1) {
		return { x % M, x % M };
	}

	pair<long long, long long> half = GeoSeries(x, ceil(n/2) );
	long long exp = half.first;
	long long sum = half.second;

	if (n % 2 == 0) {
		return { (exp * exp) % M, ((1 + exp) * sum) % M };
	}
	else {
		return { (x * exp * exp) % M, (x + x * (1 + exp) * sum) % M };
	}
}
/*
4
5 3 19
7 10 17
2 10 8
37 999999999 1234
*/