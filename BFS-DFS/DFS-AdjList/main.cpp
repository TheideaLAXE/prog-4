#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool dfs(const vector<vector<int>> &adj, const int s, const int e) {
    vector<int> v(adj.size(), 0);
    stack<int> st;
    st.push(s);
    v[s]=1;

    while (!st.empty()) {
        const int c = st.top();
        st.pop();
        if (c==e) return 1;
        for (const auto x : adj[c]) {
            if (!v[x]) {
                v[x]=1;
                st.push(x);
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> adj(10);
    adj[0].push_back(1);
    adj[0].push_back(4);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(8);

    adj[2].push_back(1);
    adj[2].push_back(3);

    adj[3].push_back(2);
    adj[3].push_back(8);

    adj[4].push_back(0);
    adj[4].push_back(5);
    adj[4].push_back(9);

    adj[5].push_back(4);
    adj[5].push_back(6);
    adj[5].push_back(7);
    adj[5].push_back(8);

    adj[6].push_back(5);
    adj[6].push_back(7);

    adj[7].push_back(5);
    adj[7].push_back(6);
    adj[7].push_back(9);

    adj[8].push_back(1);
    adj[8].push_back(3);
    adj[8].push_back(5);
    adj[8].push_back(9);

    adj[9].push_back(4);
    adj[9].push_back(7);
    adj[9].push_back(8);

    for (auto i{0u}; i<10; i++) {
        cout << i << ":";
        for (const auto e : adj[i]) cout << " " << e;
        cout << '\n';
    }
    //0->7
    cout << dfs(adj, 0, 7);


    return 0;
}
/*
 0: 1,4
 1: 0,2,8
 2: 1,3
 3: 2,8
 4: 0,5,9
 5: 4,6,7,8
 6: 5,7
 7: 5,6,9
 8: 1,3,5,9
 9: 4,7,8
*/