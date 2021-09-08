#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	int N, M, count{ 0 };

	cin >> N >> M;

	vector<string> str;
	/*결과(듣보잡들)을 담는 벡터*/
	vector<string> result;
	string tmpstr;

	for (int i = 0; i < N; i++)
	{
		cin >> tmpstr;
		str.push_back(tmpstr);
	}
	sort(str.begin(), str.end(), less<string>());

	/*algorithm의 find 함수는 복잡도가 O(n)이므로 
	반복문 중첩이 일어나면 O(n^2) 이므로 시간초과가 나오지만
	binary_search 함수는 시간복잡도가 O(log2(n))이므로 반복문이 중첩되도
	시간안에 탐색가능*/
	for (int i = 0; i < M; i++)
	{
		cin >> tmpstr;
		//binary_search 이진탐색 알고리즘을 잘 이용하자 이전엔 find로 시간초과남..
		if (binary_search(str.begin(), str.end(), tmpstr))
		{
			result.push_back(tmpstr);
			count++;
		}
	}

	//사전순 출력 유의
	sort(result.begin(), result.end(), less<string>());
	cout << count << "\n";
	for (auto it : result) {
		cout << it << "\n";
	}
}