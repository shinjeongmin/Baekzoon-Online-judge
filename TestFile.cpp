//#include <string>
//#include <vector>
//#include <set>
//#include<iostream>
//
//using namespace std;
//
//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//    set<int> elements, PickAndSum;
//
//    // elements�� numbers����ֱ�
//    for (auto i : numbers) {
//        elements.insert(i);
//    }
//
//    // �ߺ����� �ʴ� 2�� �̱�
//    for (int i = 0; i < elements.length(); i++) {
//        for (int j = i + 1; j < elements.length(); j++) {
//            PickAndSum.insert(elements[i] + elements[j]);
//        }
//    }
//
//    return answer;
//}
//
//int main() {
//    int n;
//    cin >> n;
//    
//    
//}