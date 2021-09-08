#include<iostream>
#include <vector>
using namespace std;
//모든 수를 담는 배열
vector<int> vec;
//선택된 수를 담는 배열
vector<int> select;
int k;
void combination(int num) {
	//현재 깊이가 k에 도달한 경우
	if (select.size() == k) {
		for (int i = 0; i < select.size(); i++) {
			cout << select[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = num; i < vec.size(); i++) {
		select.push_back(vec[i]);
		//다음에 위치할 숫자를 정함.
		combination(i + 1);
		select.pop_back();
	}
}
int main() {
	int num;
	cin >> num >> k;
	for (int i = 1; i <= num; i++) {
		vec.push_back(i);
	}
	combination(0);
}