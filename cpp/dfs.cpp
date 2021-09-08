#include <iostream>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <set>
#include <unordered_set>
using namespace std;

bool check[1000 + 1]; //idx 1부터 1000까지이므로 + 1
vector<vector<int>> v;
stack<int> s;

void dfs(int n) {
}

int main() {
    ios_base::sync_with_stdio;
    cin.tie(0);

    int size;
    cin >> size;

    vector<int> tempvec;
    v.assign(size + 1, tempvec);

    int n, m;
    while (cin >> n >> m)
    {
        v[n].push_back(m);
        v[m].push_back(n); // 반대방향
    }

    s.push(1); // root 노트의 값이 1이다.
    check[1] = true;
    while (!s.empty())
    {
        n = s.top();
        if (check[n])
        {
            cout << s.top() << " ";
            s.pop();
            for (int i = 0; i < v[n].size(); i++)
            {
                if (!check[v[n][i]])
                {
                    s.push(v[n][i]); // 탐색을 하지 않은 노드면 스택에 집어넣어
                    check[v[n][i]] = true; // 탐색 체크
                }
            }
        }
    }
}
/*
 1 2
 1 3
 2 4
 2 5
 3 5
 4 5
 4 6
 5 7
 5 8
 7 9
*/