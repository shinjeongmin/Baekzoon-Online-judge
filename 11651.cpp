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

		// ***주의*** 2차원벡터에 push_back할때는 벡터를 넣어야함
		vector<int> tmpvec;
		tmpvec.push_back(tmp2); // 첫번째 자리에 tmp2
		tmpvec.push_back(tmp1); // 두번째 자리에 tmp1

		vec.push_back(tmpvec); // [0],[1]이 들어있는 벡터를 2차원 벡터에
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i][1] << " " << vec[i][0] << "\n"; // 11650과 앞 뒤 바꿔 출력
	}
}