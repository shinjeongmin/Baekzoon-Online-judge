#include<iostream>
using namespace std;

int n, s, sum, cnt;
int arr[20];

void dfs(int i, int sum) {
	if (i == n) return; // 현재 인덱스가 정수의 총 갯수와 같으면 (인덱스는 0부터이므로 개수를 초과한 것) return
	if (sum + arr[i] == s) cnt++; // 현재 인덱스 수까지의 부분수열의 합이 S와 같으면 카운트 증가

	dfs(i + 1, sum); // 현재 인덱스를 합치지 않고 다음 인덱스로 넘어가는 dfs
	dfs(i + 1, sum + arr[i]); // 현재 인덱스를 합하여 다음 인덱스로 넘어가는 dfs
	/* 
	위 두 재귀함수를 통해서 
	현재 인덱스가 sum에 포함된 노드 / 포함되지 않은 노드
	두 가지 노드로 이어지는 이진트리가 생성된다.
	이 이진트리에서 depth가 최대인 노드까지 이동했을 때 
	sum이 s과 같은 경우를 골라내는 방식으로
	답을 구하는 코드이다.
	*/
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cnt = 0;
	dfs(0, 0);

	cout << cnt << "\n";
}