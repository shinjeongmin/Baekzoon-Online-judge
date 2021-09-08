//6603번 로또
//algorithm의 prev_permutation 알고리즘을 이용해서 해결.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	int k;

	while (1) {
		cin >> k;

		if (k == 0)
			break;

		vector<int> idx;
		idx.assign(k, 0);

		for (int i = 0; i < 6; i++) {
			idx[i] = 1;
		}

		vector<int> Lotto;
		for (int i = 0; i < k; i++) {
			int temp;
			cin >> temp;
			Lotto.push_back(temp);
		}


		do {
			for (int i = 0; i < k; i++)
			{
				if (idx[i])
				{
					cout << Lotto[i] << " ";
				}
			}
			cout << "\n";
		} while (prev_permutation(idx.begin(), idx.end()));
		cout << "\n";
	}
}