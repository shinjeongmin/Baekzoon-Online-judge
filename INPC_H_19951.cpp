#include<iostream>
using namespace std;

int H[100001];
int H2[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> H[i];
	}
	for (int i = 1; i <= M; i++) {
		int a, b, k;
		cin >> a >> b >> k;
		
		//
		H2[a] += k;
		if (b <= N)
			H2[b + 1] += -k;
	}

	// 누적 합 - 천재같은 발상이다 이거 진짜..
	int accum = 0;
	for (int i = 1; i <= N; i++) {
		accum += H2[i];
		H[i] += accum;
	}

	for (int i = 1; i <= N; i++) {
		cout << H[i] << " ";
	}
}