#include <iostream>
#include <vector>
using namespace std;
//��� ���� ��� �迭
vector<int> vec;
//���õ� ���� ��� �迭
vector<int> select;
int k;
//�湮���θ� ��� �迭
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