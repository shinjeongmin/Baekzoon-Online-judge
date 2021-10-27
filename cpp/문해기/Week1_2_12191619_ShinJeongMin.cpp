#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int T, N, x, query;
	stack<int> S1, S2;

	cin >> T;
	for (int t = 0; t < T; t++) {
		S1 = stack<int>();
		S2 = stack<int>();
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> query;
			if (query == 1) {
				cin >> x;
				if (!S1.empty())
					S1.push(min(S1.top(), x));
				else
					S1.push(x);
				if(!S2.empty())
					S2.push(max(S2.top(), x));
				else
					S2.push(x);

				cout << S1.top() << " " << S2.top() << "\n";
			}
			else if (query == 2) {
				if(!S1.empty()) S1.pop();
				if(!S2.empty()) S2.pop();
			}
		}
	}
}

//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int T, N;
//    cin >> T;
//    for (int t = 0; t < T; t++) {
//        cin >> N;
//        vector<int> vec;
//        int MAX = -1000, MIN = 10000;
//        
//        for (int n = 0; n < N; n++) {
//            int s, s2;
//            cin >> s;
//            if (s == 1)
//            {
//                cin >> s2;
//                vec.push_back(s2);
//            }
//            else if (s == 2)
//            {
//                if (vec.empty() == false)
//                    vec.pop_back();
//                else
//                    continue;
//            }
//             
//            MAX = -1000, MIN = 10000;
//            for (int i = 0; (unsigned int) i < vec.size(); i++) {
//                if (MAX < vec[i])
//                    MAX = vec[i];
//                if (MIN > vec[i])
//                    MIN = vec[i];
//            }
//
//            if (s == 1)
//                cout << MIN << " " << MAX << "\n";
//        }
//    }
//    return 0;
//}

/*
1
7
1 3
1 5
1 2
1 6
2
2
1 7

2
7
1 3
1 5
1 2
1 6
2
2
1 7
11
1 50
1 100
1 10
1 200
1 40
2
1 1
2
2
2
1 300
*/