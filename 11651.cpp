#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> vec;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		// ***����*** 2�������Ϳ� push_back�Ҷ��� ���͸� �־����
		vector<int> tmpvec;
		tmpvec.push_back(tmp2); // ù��° �ڸ��� tmp2
		tmpvec.push_back(tmp1); // �ι�° �ڸ��� tmp1

		vec.push_back(tmpvec); // [0],[1]�� ����ִ� ���͸� 2���� ���Ϳ�
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i][1] << " " << vec[i][0] << "\n"; // 11650�� �� �� �ٲ� ���
	}
}