#include<iostream>
#include <vector>
using namespace std;
//��� ���� ��� �迭
vector<int> vec;
//���õ� ���� ��� �迭
vector<int> select;
int k;
void combination(int num) {
	//���� ���̰� k�� ������ ���
	if (select.size() == k) {
		for (int i = 0; i < select.size(); i++) {
			cout << select[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = num; i < vec.size(); i++) {
		select.push_back(vec[i]);
		//������ ��ġ�� ���ڸ� ����.
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