#include<iostream>
#include<queue>
using namespace std;

const int MAX = 100000 + 1;
bool check[100000 + 1];
int subin, bro;

int BFS(int cur, int dtn) {

	queue<pair<int,int>> Q;

	Q.push(make_pair(cur, 0));
	check[cur] = true;

	while (!Q.empty()) {
		int cur_pop = Q.front().first;
		int sec_pop = Q.front().second;
		Q.pop();

		// µµÂøÇÏ¸é ³¡³¿.
		if (cur_pop == dtn) {
			return sec_pop;
		}

		if ( cur_pop + 1 < MAX && !check[cur_pop + 1]) {
			Q.push(make_pair(cur_pop + 1, sec_pop + 1));
			check[cur_pop + 1] = true;
		}
		if (cur_pop - 1 >= 0 && !check[cur_pop - 1]) {
			Q.push(make_pair(cur_pop - 1, sec_pop + 1));
			check[cur_pop - 1] = true;
		}
		if (2 * cur_pop < MAX && !check[2 * cur_pop]) {
			Q.push(make_pair(cur_pop * 2, sec_pop + 1));
			check[cur_pop * 2] = true;
		}
	}
}

int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);

	cin >> subin >> bro;

	cout << BFS(subin, bro) << "\n";
}
// Á¦ÇÑ½Ã°£ 6:20