// <algorithm> ����� next_permutation �Լ��� �̿��� Ǯ��.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		v.push_back(i + 1);
	}

	do{
		for (auto it : v) {
			cout << it << " ";
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));
}