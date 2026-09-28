#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool dfs(const vector<pair<int,int>> &EL, const int s, const int e, vector<bool> &v) {
    if (s==e) return 1;
    for (const auto &[fst, snd] : EL) {
        if (fst==s && !v[snd]) {
            v[snd]=1;
            if (dfs(EL, snd, e, v)) return 1;
        }
        else if (snd==s && !v[fst]) {
            v[fst]=1;
            if (dfs(EL, fst, e, v)) return 1;
        }
    }

    return 0;
}

bool dfs_call(const vector<pair<int,int>> &EL, const int s, const int e) {
    set<int> S;
    for (const auto &[fst, snd] : EL) {
        S.insert(fst);
        S.insert(snd);
    }
    vector<bool> v(S.size(), 0);
    return dfs(EL, s, e, v);
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

    cout << dfs_call(EL, 0, 7) << '\n';
    cout << dfs_call(EL, 0, 10) << '\n';

    return 0;
}