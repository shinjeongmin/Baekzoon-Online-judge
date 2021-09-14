//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//using namespace std;
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
//		// 출력
//		for (int i = 0; i < N; i++) {
//			
//		}
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
