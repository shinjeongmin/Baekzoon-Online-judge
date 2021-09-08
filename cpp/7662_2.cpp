#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		multiset<int, less<int>> q;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++)
		{
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I')
			{
				// ť�� ����
				q.insert(n);
			}
			else//c == 'D'
			{
				if (n == 1)
				{
					if(!q.empty())
						//�ִ� ����
						q.erase(--q.end());
				}
				else //n == -1
				{
					if(!q.empty())
						//�ּڰ� ����
						q.erase(q.begin());
				}
			}
		}

		if (q.empty())
		{
			cout << "EMPTY\n";
		}
		else 
		{
			cout << *--q.end() << " " << *q.begin() << "\n";
		}
	}
}