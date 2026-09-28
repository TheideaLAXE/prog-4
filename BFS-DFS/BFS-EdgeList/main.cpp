#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int bfs(const vector<pair<int,int>> &EL, const int s, const int e) {
    set<int> V;
    for (const auto &i : EL) {
        V.insert(i.first);
        V.insert(i.second);
    }
    vector<int> v(V.size(), 0);
    vector<int> res(V.size(), 0);
    v[s]=1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        const int c = q.front();
        if (c==e) return res[e];
        q.pop();
        for (const auto &i : EL) {
            if (i.first==c && !v[i.second]) {
                v[i.second]=1;
                q.push(i.second);
                res[i.second]=res[c]+1;
            }
            else if (i.second==c && !v[i.first]) {
                v[i.first]=1;
                q.push(i.first);
                res[i.first]=res[c]+1;
            }
        }
    }
    return res[e];
}


int main() {
    vector<pair<int,int>> EL;

    EL.push_back({0, 1});
    EL.push_back({0, 4});
    EL.push_back({1, 2});
    EL.push_back({1, 8});
    EL.push_back({2, 3});
    EL.push_back({3, 8});
    EL.push_back({4, 5});
    EL.push_back({4, 9});
    EL.push_back({5, 6});
    EL.push_back({5, 7});
    EL.push_back({5, 8});
    EL.push_back({6, 7});
    EL.push_back({7, 9});
    EL.push_back({8, 9});

    for (auto e : EL) {
        cout << e.first << " " << e.second <<'\n';
    }

    cout << bfs(EL, 0, 7);

    return 0;
}