#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vec1, vec2;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
		// 각 벡터에 값 저장
	{
		int x, y;
		cin >> x >> y;
		vec1.push_back(x);
		vec2.push_back(y);
	}

	int temp;

	for (int j = 0; j < N - 1; j++)
	{
		for (int i = 0; i < N - 1; i++) // x자리 버블정렬
		{
			if (vec1[i] > vec1[i + 1])
			{
				temp = vec1[i];
				vec1[i] = vec1[i + 1];
				vec1[i + 1] = temp;

				temp = vec2[i];
				vec2[i] = vec2[i + 1];
				vec2[i + 1] = temp;
			}

			// x자리가 같을 때만
			if (vec1[i] == vec1[i + 1] &&
				vec2[i] > vec2[i + 1])
			{
				temp = vec1[i];
				vec1[i] = vec1[i + 1];
				vec1[i + 1] = temp;

				temp = vec2[i];
				vec2[i] = vec2[i + 1];
				vec2[i + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << vec1[i] << " " << vec2[i] << "\n";
	}
}