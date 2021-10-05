#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> graph[50001];
int prefix[50001] = { 0, };

void dfs(int idx) {
	if (graph[idx].size() == 0) return;
	for (auto i : graph[idx]) {
		prefix[i] += prefix[idx] + 1;
		dfs(i);
	}
}

void init() {
	for (int i = 0; i < 50001; i++) {
		graph[i].clear();
		prefix[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		init();
		int N;
		cin >> N;
		for (int n = 0; n < N-1; n++) {
			int A, B;
			cin >> A >> B;
			graph[A].push_back(B);
		}
		for (int n = 0; n < N; n++) {
			string S;
			cin >> S;
			prefix[n + 1] = S.length();
		}

		// 탐색하면서 (자식의 길이) += (부모의 길이) + 1
		int curIdx = 1;
		dfs(curIdx);

		// 출력
		for (int i = 1; i <= N; i++) {
			cout << prefix[i] << "\n";
		}
	}
}
/*
2
10
1 2
1 3
1 4
2 5
2 6
3 7
3 8
6 9
6 10
root
usr
var
boot
bin
local
log
tmp
src
lib
5
1 2
4 3
2 4
1 5
root
aaa
bbbb
c
dddddd
*/