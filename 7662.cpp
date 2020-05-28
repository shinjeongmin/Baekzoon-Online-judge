#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
using namespace std;

bool check[1000000];

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		priority_queue<pair<int,int>, vector<pair<int,int>>
			, greater<pair<int,int>>> min_heap; // 최소힙
		priority_queue<pair<int,int>,vector<pair<int,int>>
			, less<pair<int,int>>> max_heap; // 최대힙
		int k;
		cin >> k;

		for (int i = 0; i < k; i++)
		{
			char c;
			int temp;
			cin >> c >> temp;

			pair<int, int> temppair{temp,i};

			if (c == 'I')
			{
				// 힙에 정수값 저장
				min_heap.push(temppair);
				max_heap.push(temppair);

				// 현재 큐에 들어있는 값인가?
				check[i] = true;
			}
			else
			{
				if (temp == 1) //최댓값 삭제
				{
					// 현재 큐에 들어있지 않은 (check[] == 0) 경우 삭제
					while (!max_heap.empty()
						&& !check[max_heap.top().second])
						max_heap.pop();

					// 최댓값(check == 1인 top의 값)의 check를 false로 변경
					if (!max_heap.empty())
					{
						check[max_heap.top().second] = false;
						max_heap.pop();
					}
				}
				else
				{// temp == -1
					// 현재 큐에 들어있지 않은 (check[] == 0) 경우 삭제
					while (!min_heap.empty()
						&& !check[min_heap.top().second])
						min_heap.pop();

					// 최솟값(check == 1인 top의 값)의 check를 false로 변경
					if (!min_heap.empty())
					{
						check[min_heap.top().second] = false;
						min_heap.pop();
					}
				}
			}
		}

		// 마지막으로 유효하지 않은 값 검출
		while (!max_heap.empty()
			&& !check[max_heap.top().second])
			max_heap.pop();
		while (!min_heap.empty()
			&& !check[min_heap.top().second])
			min_heap.pop();

		if (min_heap.empty() && max_heap.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << max_heap.top().first << " " << min_heap.top().first << "\n";
		}
	}
}