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
			, greater<pair<int,int>>> min_heap; // �ּ���
		priority_queue<pair<int,int>,vector<pair<int,int>>
			, less<pair<int,int>>> max_heap; // �ִ���
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
				// ���� ������ ����
				min_heap.push(temppair);
				max_heap.push(temppair);

				// ���� ť�� ����ִ� ���ΰ�?
				check[i] = true;
			}
			else
			{
				if (temp == 1) //�ִ� ����
				{
					// ���� ť�� ������� ���� (check[] == 0) ��� ����
					while (!max_heap.empty()
						&& !check[max_heap.top().second])
						max_heap.pop();

					// �ִ�(check == 1�� top�� ��)�� check�� false�� ����
					if (!max_heap.empty())
					{
						check[max_heap.top().second] = false;
						max_heap.pop();
					}
				}
				else
				{// temp == -1
					// ���� ť�� ������� ���� (check[] == 0) ��� ����
					while (!min_heap.empty()
						&& !check[min_heap.top().second])
						min_heap.pop();

					// �ּڰ�(check == 1�� top�� ��)�� check�� false�� ����
					if (!min_heap.empty())
					{
						check[min_heap.top().second] = false;
						min_heap.pop();
					}
				}
			}
		}

		// ���������� ��ȿ���� ���� �� ����
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