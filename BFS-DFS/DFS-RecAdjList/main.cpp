#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool dfs(const vector<vector<int>> &adj, const int s, const int e, vector<bool> &v) {
    if (s==e) return 1;
    for (const auto x : adj[s]) {
        if (!v[x]) {
            v[x]=1;
            if (dfs(adj, x, e, v)) return 1;
        }
    }
    return 0;
}

bool dfs_call(const vector<vector<int>> &adj, const int s, const int e) {
    vector<bool> v(adj.size(), 0);
    v[s]=1;
    return dfs(adj, s, e, v);
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
    cout << dfs_call(adj, 0, 7) << '\n';
    cout << dfs_call(adj, 0, 10);


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