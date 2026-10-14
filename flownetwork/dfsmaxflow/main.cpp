#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<pair<int, int>, int>> EL;

int dfs(int c, int t, int f, vector<int>& par) {
    if (c==t) return f;

    for (int i=0; i<EL.size(); i++) {
        int u=EL[i].first.first, v=EL[i].first.second, cap=EL[i].second;

        if (u==c && par[v]==-1 && cap>0) {
            par[v]=i;
            int pf=dfs(v, t, min(f, cap), par);
            if (pf>0) return pf;
        }
    }
    return 0;
}

int maxflow(int s, int t) {
    int f = 0;
    vector<int> par(n+1, -1);

    while (true) {
        fill(par.begin(), par.end(), -1);
        par[s] = -2;
        int nf = dfs(s, t, 1e9, par);
        if (!nf) break;
        f+=nf;
        int c=t;

        while (c!=s) {
            int id=par[c], prev=EL[id].first.first;
            EL[id].second-=nf;
            
            if (id<m)
                EL[id+m].second+=nf;
            else
                EL[id-m].second+=nf;
            c=prev;
        }
    }
    return f;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        EL.push_back({{u, v}, w});
        EL.push_back({{v, u}, 0});
    }

    int source = 1, sink = n;
    cout << maxflow(source, sink);
    return 0;
}