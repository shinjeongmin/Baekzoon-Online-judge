#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>
using namespace std;

bool cmp(string a, string b) {
	if (a.size() < b.size()) // ���� �ܾ �� ��� ��ü
		return true; 
	else if(a.size() == b.size())
	{
		if (a < b) {
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<string> vec;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		vec.push_back(temp);
	}

	stable_sort(vec.begin(), vec.end(),cmp);

	// set�� �̿����� �ʰ� ������ i + 1�ε����� �ߺ� ����� �Ÿ�
	for (int i = 0; i < N; i++) {
		if (i != N - 1)
		{
			if (vec[i + 1] == vec[i])
			{
				continue;
			}
			else
				cout << vec[i] << "\n";
		}
		else
			cout << vec[i] << "\n";
	}
}