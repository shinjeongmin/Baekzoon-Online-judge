#include <iostream>
#include <vector>
using namespace std;
//모든 수를 담는 배열
vector<int> vec;
//선택된 수를 담는 배열
vector<int> select;
int k;
//방문여부를 담는 배열
vector<bool> check;
void permutation() {
	if (select.size() == k) {
		for (int i = 0; i < select.size(); i++) {
			cout << select[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < vec.size(); i++) {
		if (check[i]) {
			continue;
		}
		select.push_back(vec[i]);
		check[i] = true;
		permutation();
		select.pop_back();
		check[i] = false;
	}
}

int main() {
	int num;
	cin >> num >> k;
	for (int i = 1; i <= num; i++)
	{
		vec.push_back(i);
	}
	check.assign(num, 0);
	permutation();
}