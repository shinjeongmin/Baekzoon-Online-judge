#include <iostream>
#include <algorithm>
#include <vector>
#define STANDARD_BENEFIT 1000

using namespace std;

int Max(vector<int> v) {
	int max = -1;
	for (int i = 0; i < max; i++)
	{
		if (v[i] > max)
		{
			max = v[i];
		}
	}

	return max;
}

bool compare(int a, int b) {
	return a > b;
}



int main(){
	int hours, num_pc, res_num;
	cin >> num_pc >> res_num >> hours;


	vector<vector<int>> list;   //reservations[pcnumber][reservation]
	vector <int> b;         //answer[pcnumber]

	for (int i = 0; i <= num_pc; i++) {
		vector<int> tmp_list;
		list.push_back(tmp_list);
		b.push_back(0);
	}

	for (int i = 0; i < res_num; i++) {
		int x, y;
		cin >> x >> y;

		if (0 < y && y <= hours)
			list[x].push_back(y);
	}

	for (int i = 1; i <= num_pc; i++) {
		if (list[i].size() > 0)
			sort(list[i].begin() + 1, list[i].end(), compare);
	}

	for (int i = 1; i <= num_pc; i++) {
		int benefit = 0;

		if (static_cast<int>(list[i].size()) > 0)
		{
			do
			{
				int tmp_b = 0;
				int max_t = 0;
				for (int j = 0; j < static_cast<int>(list[i].size()); j++)
				{
					if (max_t + list[i][j] > hours) break;

					max_t += list[i][j];
					tmp_b += list[i][j] * STANDARD_BENEFIT;
				}

				if (tmp_b > benefit)
				{
					benefit = tmp_b;
				}

			} while (next_permutation(list[i].begin() + 1, list[i].end()));
		}

		b[i] = benefit;
	}

	for (int i = 1; i <= num_pc; i++) {
		cout << i << " " << b[i] << "\n";
	}

	return 0;
}