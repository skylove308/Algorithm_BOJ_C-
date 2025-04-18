#include <bits/stdc++.h>
using namespace std;

static int N;
static vector<list<int>> tree;
static vector<bool> visited;
static vector<int> parents;

void dfs(int t){
    visited[t] = true;
    for(int nt : tree[t]){
        if(visited[nt]){
            parents[t] = nt;
            continue;
        }
        dfs(nt);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    cin >> N;
    tree.resize(N+1);
    visited.resize(N+1);
    parents.resize(N+1);

    for(int i=0; i<N-1; i++){
        int A,B;
        cin >> A >> B;
        tree[A].push_back(B);
        tree[B].push_back(A);
    }
    
    dfs(1);

    for(int i=2; i<=N; i++){
        cout << parents[i] << '\n';
    }
    
}