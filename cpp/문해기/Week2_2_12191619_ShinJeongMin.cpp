#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
using namespace std;

int T, N, costAnswer;
int resourceA[10000 + 1];
int resourceB[10000 + 1];
pair<int, int> resourceSum[10000 + 1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> resourceA[i] >> resourceB[i];
			resourceSum[i] = make_pair(resourceA[i] + resourceB[i], i);
		}
		sort(&resourceSum[1], &resourceSum[N+1], greater<pair<int,int>>());
		costAnswer = 0;

		for (int i = 1; i <= N; i++) {
			if (i % 2 == 1) {
				costAnswer += resourceA[resourceSum[i].second];
			}
			else{
				costAnswer -= resourceB[resourceSum[i].second];
			}
		}
		cout << costAnswer << "\n";
	}
}

//// sort 해놓고 가장 유리한(가장 먼저인) 것부터 가져가는 방법으로 해결해야함.
//
//bool inhaCon(pair<int, int> i, pair<int, int> j) {
//	return i.first > j.first;
//}
//
//bool biryCon(pair<int, int> i, pair<int, int> j) {
//	return i.second > j.second;
//}
//
//bool SumCon(pair<int, int> i, pair<int, int> j) {
//	return i.first + i.second > j.first + j.second;
//}
//
//int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int T;
//	cin >> T;
//	for (int t = 0; t < T; t++) {
//		int N;
//		cin >> N;
//		vector<pair<int, int>> resource;
//		int inhaTotal = 0, biryongTotal = 0;
//		for (int j = 0; j < N; j++) {
//			int temp1, temp2;
//			cin >> temp1 >> temp2;
//			pair<int, int> tempPair = make_pair(temp1, temp2);
//			resource.push_back(tempPair);
//		}
//
//		sort(resource.begin(), resource.end(), SumCon);
//
//		// 주의 : 다른 쪽이 가져간 자원을 못가져감
//		for (int j = 0; j < N; j++) {
//			if (j % 2 == 0) { // 인하차례
//				auto indexPtr = max_element(resource.begin(), resource.end(), inhaCon);
//				inhaTotal += (*indexPtr).first;
//				resource.erase(indexPtr);
//			}
//			else // 비룡차례
//			{
//				auto indexPtr = max_element(resource.begin(), resource.end(), biryCon);
//				biryongTotal += (*indexPtr).second;
//				resource.erase(indexPtr);
//			}
//		}
//		cout << inhaTotal - biryongTotal << "\n";
//	}
//}

/*
1
3
30 20 
10 10 
5 20
*/