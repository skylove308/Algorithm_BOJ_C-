#include <bits/stdc++.h>
using namespace std;

static int V;
static vector<list<pair<int, int>>> tree;
static vector<bool> visited;
static int maxNode = 0;
static int maxLen = 0;

void dfs(int v, int w){
    visited[v] = true;

    if(w > maxLen){
        maxNode = v;
        maxLen = w;
    }

    for(auto t: tree[v]){
        if(visited[t.first]) continue;
        dfs(t.first, w + t.second);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> V;
    tree.resize(V+1);
    visited.resize(V+1);

    int VS, VE, D;
    for(int i=1; i<=V; i++){
        cin >> VS;

        while(true){
            cin >> VE;
            if(VE == -1) break;
            cin >> D;
            tree[VS].push_back({VE,D});
        }
    }

    dfs(1, 0);
    maxLen = 0;
    for(int i=1; i<=V; i++){
        visited[i] = false;
    }
    dfs(maxNode, 0);

    cout << maxLen << '\n';
    return 0;
}
