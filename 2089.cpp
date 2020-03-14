#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> v;
	cin >> N;

	if (N == 0) //0의 예외처리
		v.push_back(0);

	while (N != 0) //0이 될때 까지 나누는 것이므로 0는 예외처리로 따로
	{
		if (N % -2 == -1) //만약 나머지가 -1이면 (나머지는 무조건 0,1이어야함)
		{
			v.push_back(1); //나머지를 1로 만들고
			N = N / -2 + 1; //몫의 값을 1 증가시킨다.
		}
		else
		{
			v.push_back(N % -2);
			N /= -2;
		}
	}

	vector<int>::reverse_iterator iter = v.rbegin(); //벡터를 반대로 출력하기 위한 이터레이터

	for (iter = v.rbegin(); iter != v.rend(); iter++)
	{
		cout << *iter;
	}
}