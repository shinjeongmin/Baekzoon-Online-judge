//#include <iostream>
//#include <deque>
//#include <queue>
//#include <stack>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <utility>
//#include <set>
//#include <unordered_set>
//using namespace std;
//
//bool check[1000 + 1]; //idx 1���� 1000�����̹Ƿ� + 1
//vector<vector<int>> v;
//queue<int> q;
//
//int main() {
//	ios_base::sync_with_stdio;
//	cin.tie(0);
//    
//    int size;
//    cin >> size;
//
//    vector<int> tempvec;
//    v.assign(size + 1, tempvec);
//
//	int n, m;
//	while (cin >> n >> m)
//	{
//		v[n].push_back(m);
//		v[m].push_back(n); // �ݴ����
//	}
//
//    q.push(1); // root ��Ʈ�� ���� 1�̴�.
//    check[1] = true;
//    while (!q.empty())
//    {
//        n = q.front();
//        if (check[n])
//        {
//            cout << q.front() << " ";
//            q.pop();
//            for (int i = 0; i < v[n].size(); i++)
//            {
//                if (!check[v[n][i]])
//                {
//                    q.push(v[n][i]); // Ž���� ���� ���� ���� ���ÿ� ����־�
//                    check[v[n][i]] = true; // Ž�� üũ
//                }
//            }
//        }
//    }
//}
///*
//9
//1 2
//1 3
//2 4
//2 5
//3 5
//4 5
//4 6
//5 7
//5 8
//7 9
//*/