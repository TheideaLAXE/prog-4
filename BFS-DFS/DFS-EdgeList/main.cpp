#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;


bool dfs(const vector<pair<int,int>> &EL, const int s, const int e) {
    set<int> S;
    for (const auto &i : EL) {
        S.insert(i.first);
        S.insert(i.second);
    }
    vector<int> v(S.size(), 0);
    stack<int> st;
    st.push(s);
    while (!st.empty()) {
        const int c = st.top();
        st.pop();
        if (c==e) return 1;
        for (const auto &i : EL) {
            if (i.first==c && !v[i.second]) {
                v[i.second]=1;
                st.push(i.second);
            }
            else if (i.second==c && !v[i.first]) {
                v[i.first]=1;
                st.push(i.first);
            }
        }
    }

    return 0;
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

    cout << dfs(EL, 0, 7) << '\n';
    cout << dfs(EL, 0, 10) << '\n';

    return 0;
}