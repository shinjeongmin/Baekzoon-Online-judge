#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, less<int>> Max_heap;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (Max_heap.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << Max_heap.top() << "\n";
				Max_heap.pop();
			}
		}
		else
		{
			Max_heap.push(x);
		}
	}
}