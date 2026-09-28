#include <iostream>
#include <queue>
#include <vector>
using namespace std;
bool bfs(const vector<vector<bool>> &adj, const int s, const int e) {
    vector<int> v(adj.size(), 0);
    vector<int> res(adj.size(), 0);
    v[s]=1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        const int c = q.front();
        if (c==e) return res[e];
        q.pop();
        for (auto i{0u}; i<adj[c].size(); i++) {
            if (adj[c][i] && !v[i]) {
                v[i]=1;
                q.push(static_cast<int>(i));
                res[i]=res[c]+1;
            }
        }
    }
    return res[e];
}

int main() {
    vector<vector<bool>> adj(10, vector<bool>(10, 0));

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
    cout << bfs(adj, 0, 7);


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