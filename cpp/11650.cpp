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
		tmpvec.push_back(tmp1); // ù��° �ڸ��� tmp1
		tmpvec.push_back(tmp2); // �ι�° �ڸ��� tmp2

		vec.push_back(tmpvec); // [0],[1]�� ����ִ� ���͸� 2���� ���Ϳ�
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i][0] << " " << vec[i][1] << "\n";
	}
}