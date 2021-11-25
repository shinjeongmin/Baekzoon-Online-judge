#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int T, N, A, B, last, cnt;
vector<pair<int,int>> rooms;
vector<pair<int, int>>::iterator it = rooms.begin();

bool cmp(pair<int,int> a, pair<int, int> b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cnt = 0;
		rooms = vector<pair<int, int>>();
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> A >> B;
			rooms.push_back({ A, B });
		}

		sort(rooms.begin(), rooms.end(), cmp);
		int score = rooms[0].second;
		cnt++;
		
		for (auto room : rooms) {
			if (score > room.second) {
				score = room.second;
				cnt++;
			}
		}

		/*cout << "rooms\n";
		for (auto room : rooms)
			cout << room.first << " " << room.second << "\n";*/
		cout << cnt << "\n";
	}
}

/*
3
7
90 1500
50 500
100 3000
5 4500
10 3100
85 700
20 4000
3
50 1000
20 3000
30 2000
3
50 1000
60 3000
20 2000
*/