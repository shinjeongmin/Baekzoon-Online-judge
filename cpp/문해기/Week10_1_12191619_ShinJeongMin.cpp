#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int T, A, B;
vector<int> road[10000]; // road[A] : A번 방에서 이동할 수 있는 방의 번호를 저장
int check[10000];
queue<int> que; // BFS 알고리즘에서 사용할 큐

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i <= 9999; i++) { // i번 방에서 이동할 수 있는 방의 번호를 계산
		if (i != 0) {
			road[i].push_back(i - 1);
		}
		if (i != 9999) {
			road[i].push_back(i + 1);
		}
		int num = 0, temp = i; // 방번호를 역순으로 변경한 번호의 방
		for (int j = 0; j <= 3; j++) {
			num = num * 10 + temp % 10;
			temp = temp / 10;
		}
		road[i].push_back(num);
	}

	cin >> T;
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i <= 9999; i++) {
			check[i] = 10000;
		}
		cin >> A >> B;
		check[A] = 0;
		que.push(A);
		while (que.empty() == false) { // 큐에 더이상 원소가 없으면 종료
			int now = que.front();
			que.pop();
			for (int i = 0; i < road[now].size(); i++) { // now번 방에서 이동할 수 있는 방으로 이동
				if (check[road[now][i]] > check[now] + 1) { // 방문하지 않은 방을 큐에 삽입
					que.push(road[now][i]);
					check[road[now][i]] = check[now] + 1;
				}
			}
		}
		cout << check[B] << "\n";
	}
}