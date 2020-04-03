#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string>
using namespace std;

bool comp(tuple<string, int, int, int> a, 
	tuple<string, int, int, int> b) 
{
	// ------조건문 확인 순서 주의--------

	// 국어점수가 감소하는 순서로
	if (get<1>(a) < get<1>(b))
		return false;
	//모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로
	else if (get<1>(a) == get<1>(b) &&
		get<2>(a) == get<2>(b) &&
		get<3>(a) == get<3>(b))
		return get<0>(a) < get<0>(b);
	// 국어점수와 영어점수가 같으면 수학 점수가 감소하는 순서로
	else if (get<1>(a) == get<1>(b) &&
		get<2>(a) == get<2>(b))
		return get<3>(a) > get<3>(b);
	// 국어점수가 같으면 영어점수가 증가하는 순서로
	else if (get<1>(a) == get<1>(b))
		return get<2>(a) < get<2>(b);
	// 나머지는 국어점수가 다른경우이므로 국어점수의 감소순
	else
		return get<1>(a) > get<1>(b);
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);

	vector<tuple<string, int, int, int>> KEM;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		tuple<string, int, int, int> temptuple;
		string tempstring;
		int tempint1, tempint2, tempint3;

		cin >> tempstring >> tempint1 >> tempint2 >> tempint3;
		
		get<0>(temptuple) = tempstring;
		get<1>(temptuple) = tempint1;
		get<2>(temptuple) = tempint2;
		get<3>(temptuple) = tempint3;

		KEM.push_back(temptuple);
	}

	sort(KEM.begin(), KEM.end(), comp);

	for (int i = 0; i < N; i++) 
	{
		cout << get<0>(KEM[i]) << /*" "
			<< get<1>(KEM[i]) << " "
			<< get<2>(KEM[i]) << " "
			<< get<3>(KEM[i]) << */"\n";
	}
}