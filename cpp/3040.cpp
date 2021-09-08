#include<iostream>
#include<algorithm>
#include<vector>
#define endl '\n'
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int sum{ 0 };
	vector<int> dwarves;
	vector<int> check = { 0,0,1,1,1,1,1,1,1 };

	for (int i = 0; i < 9; i++)
	{
		int dwarf;
		cin >> dwarf;
		dwarves.push_back(dwarf);
	}
	sort(dwarves.begin(), dwarves.end());
	do {
		sum = 0;
		for (int i = 0; i < 9;i++) {
			if (check[i] == 1){
				sum += dwarves[i];
			}
		}
		if (sum == 100)
			break;
	} while (next_permutation(check.begin(), check.end()));


	for (int i = 0; i < 9; i++) {
		if (check[i] == 1) {
			cout << dwarves[i] << endl;
		}
	}
}