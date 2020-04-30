#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int main() 
{

	int max; // 프린터 큐에서 가장큰 값을 넣는 곳.
	int testcase, N, M, num{ 0 }; // N : 프린터 큐 길이, M : 궁금한 인덱스
	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		cin >> N >> M;
		num = 0;

		queue<int> printerq;
		queue<int> idxque;
		vector<int> max_ele; // 프린터 큐의 중요도를 오름차순으로 배열한 벡터

		for (int i = 0; i < N; i++) idxque.push(i); // 인덱스 전용 큐
		for (int i = 0; i < N; i++)
			// 프린터 큐에 입력값 넣기
		{
			int temp;
			cin >> temp;
			printerq.push(temp);
			max_ele.push_back(temp);
		}

		sort(max_ele.begin(), max_ele.end()); // 벡터 오름차순 정렬

		while (1)
		{
			// 큐에서의 최댓값(= 벡터에서의 최댓값) 찾기
			max = *max_element(max_ele.begin(), max_ele.end());

			if (printerq.front() == max)
				// 큐에 있는 수 중 중요도가 가장높은 수이면.
			{
				// 프린터 큐의 앞의 숫자 빼기
				printerq.pop();

				// 벡터에서 최댓값 하나 빼기
				max_ele.erase(max_ele.end() - 1); // 주소값. 인덱스로 해야하나?
				num++; //카운터 증가


				if (M == idxque.front()) 
					//
				{
					break;
				}
				// 인덱스 큐의 앞의 숫자 빼기
				idxque.pop();
			}
			else // max가 아니거나, 인덱스가 안맞거나 하면 queue 순환
			{
				int temp;
				temp = printerq.front();
				printerq.push(temp);
				printerq.pop();

				temp = idxque.front();
				idxque.push(temp);
				idxque.pop();
			}
		}

		cout << num << "\n";
	}
}