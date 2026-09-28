#include <iostream>
#include <vector>
using namespace std;
bool dfs(const vector<vector<bool>> &adj, const int s, const int e, vector<bool> &v) {
    v[s]=1;
    if (s==e) return 1;
    for (auto i{0u}; i<adj[s].size(); i++) {
        if (adj[s][i] && !v[i]) {
            if (dfs(adj, static_cast<int>(i), e, v)) return 1;
        }
    }
    return 0;
}

bool dfs_call(const vector<vector<bool>> &adj, const int s, const int e) {
    vector<bool> v(adj.size(), 0);
    return dfs(adj, s, e, v);
}

int main() {
    vector<vector<bool>> adj(11, vector<bool>(11, 0));

    adj[0][1] = 1; adj[1][0] = 1;
    adj[0][4] = 1; adj[4][0] = 1;

    adj[1][2] = 1; adj[2][1] = 1;
    adj[1][8] = 1; adj[8][1] = 1;

    adj[2][3] = 1; adj[3][2] = 1;

    adj[3][8] = 1; adj[8][3] = 1;

    adj[4][5] = 1; adj[5][4] = 1;
    adj[4][9] = 1; adj[9][4] = 1;

    adj[5][6] = 1; adj[6][5] = 1;
    adj[5][7] = 1; adj[7][5] = 1;
    adj[5][8] = 1; adj[8][5] = 1;

    adj[6][7] = 1; adj[7][6] = 1;

    adj[7][9] = 1; adj[9][7] = 1;

    adj[8][9] = 1; adj[9][8] = 1;

    for (auto i{0u}; i<adj.size(); i++) {
        for (auto j{0u}; j<adj.size(); j++) {
            cout << adj[i][j] << "  ";
        }
        cout << '\n';
    }
    //0->7
    cout << dfs_call(adj, 0, 7) << '\n';
    //0->10, false
    cout << dfs_call(adj, 0, 10) << '\n';


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