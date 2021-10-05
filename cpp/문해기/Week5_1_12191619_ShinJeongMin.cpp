#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int N;
int prefix[5001] = { 0, };
int signal[5001] = { 0, };

void init() {
	for (int i = 0; i < 501; i++) {
		prefix[i] = 0;
		signal[i] = 0;
	}
}

void compute() {
	prefix[1] = 0;
	int k = 0;

	for (int i = 2; i <= N; i++) {
		while (k > 0 && signal[i] != signal[k+1]) {
			k = prefix[k];
		}
		if (signal[i] == signal[k + 1])
			k += 1;
		prefix[i] = k;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		init();
		for (int i = 1; i <= N; i++) {
			cin >> signal[i];
		}
		compute();
		for (int i = 1; i <= N - prefix[N]; i++) {
			if(i == N-prefix[N])
				cout << signal[i];
			else
				cout << signal[i] << " ";
		}
		cout << "\n";
	}
}
/*
4
10
5 2 1 5 5 2 1 5 5 2
10
1 2 3 4 5 6 7 1 2 3
10
1 2 3 4 5 6 7 1 2 2
15
1 2 1 2 1 2 1 2 1 2 1 2 1 2 1
*/
/*string flushBuffer;
getline(cin, flushBuffer);
string X;
getline(cin, X);
X.erase(remove(X.begin(), X.end(), ' '), X.end());*/