#include <iostream>
#include <algorithm>
#include <vector>
#define HOUSE 1000001
using namespace std;
int N, M;
int house[HOUSE];

bool check(int len) {
	int h = 1;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (h <= house[i]) {
			h = house[i] + len;
			cnt += 1;
		}
		if (cnt == M)
			return true;
	}
	return false;
}

int binsearch(int left, int right) {
	int mid;
	if (left == right) {
		return left;
	}
	if (left + 1 == right) {
		if (check(right) == true)
			return right;
		else
			return left;
	}
	mid = (left + right) / 2;
	if (check(mid) == true)
		return binsearch(mid, right);
	else
		return binsearch(left, mid-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
	cout << binsearch(1, house[N - 1]);
}

/*
5 3
1
2
4
8
9
*/