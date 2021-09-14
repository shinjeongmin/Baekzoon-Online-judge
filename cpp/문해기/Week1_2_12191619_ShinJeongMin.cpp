#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        vector<int> vec;
        int MAX = -1000, MIN = 10000;
        
        for (int n = 0; n < N; n++) {
            int s, s2;
            cin >> s;
            if (s == 1)
            {
                cin >> s2;
                vec.push_back(s2);
            }
            else if (s == 2)
            {
                if (vec.empty() == false)
                    vec.pop_back();
                else
                    continue;
            }

            MAX = -1000, MIN = 10000;
            for (int i = 0; (unsigned int) i < vec.size(); i++) {
                if (MAX < vec[i])
                    MAX = vec[i];
                if (MIN > vec[i])
                    MIN = vec[i];
            }

            if (s == 1)
                cout << MIN << " " << MAX << "\n";
        }
    }
    return 0;
}
