#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

int A, B, C;
bool check[201][201][201];
vector<int> A_empty;

struct NowCapacity {
	int a, b, c;
};

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> A >> B >> C;
	NowCapacity cur;

	queue<NowCapacity> q;
	q.push({ 0, 0, C });

	while (!q.empty())
	{
		cur = q.front(); // 가장 먼저 넣었던 값 꺼내기 FIFO
		q.pop();

		// 이미 체크한 값이면 넘기기
		if (check[cur.a][cur.b][cur.c])
			continue;

		check[cur.a][cur.b][cur.c] = true;

		if (cur.a == 0)
			//물통 A가 비어있는 경우의 C에 담긴 양을 결과로 저장.
			A_empty.push_back(cur.c);

		// 물 옮기기
		// a->b
		if (cur.a + cur.b > B) {
			q.push({ cur.a + cur.b - B,B, cur.c });
		}
		else {
			q.push({ 0, cur.a + cur.b, cur.c });
		}

		// a->c
		if (cur.a + cur.c > C) {
			q.push({ cur.a + cur.c - C, cur.b, C });
		}
		else {
			q.push({ 0, cur.b, cur.a + cur.c });
		}

		// b->a
		if (cur.a + cur.b > A) {
			q.push({A, cur.b + cur.a - A, cur.c});
		}
		else {
			q.push({cur.a + cur.b, 0, cur.c});
		}

		// b->c
		if (cur.b + cur.c > C) {
			q.push({cur.a, cur.b + cur.c - C, C});
		}
		else {
			q.push({cur.a, 0, cur.b + cur.c});
		}

		// c->a
		if (cur.a + cur.c > A) {
			q.push({A, cur.b, cur.a + cur.c - A});
		}
		else {
			q.push({cur.a + cur.c, cur.b, 0});
		}

		// c->b
		if (cur.b + cur.c > B) {
			q.push({cur.a, B, cur.b + cur.c - B});
		}
		else {
			q.push({cur.a, cur.b + cur.c, 0});
		}
	}

	sort(A_empty.begin(), A_empty.end(), less<int>());

	for (auto it : A_empty) {
		cout << it << " ";
	}
}
/*
*/