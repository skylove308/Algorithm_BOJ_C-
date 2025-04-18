#include <bits/stdc++.h>
using namespace std;

static vector<list<int>> tree;

int dfs(int t){
    int leaves = 0;
    if(tree[t].empty()) return 1;
    for(int nt: tree[t]){
        leaves += dfs(nt);
    }
    return leaves;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 

    int N;
    cin >> N;
    tree.resize(N);
    vector<int> parentTree(N);

    int root = 0;
    for(int i=0; i<N; i++){
        int T;
        cin >> T;

        parentTree[i] = T;

        if(T == -1) root = i;
        else tree[T].push_back(i);
    }

    int erased_node;
    cin >> erased_node;

    int leaves = dfs(root);
    int erased_leaves = dfs(erased_node);

    if(root == erased_node){
        cout << 0 <<'\n';
    }
    else if(tree[parentTree[erased_node]].size() == 1){
        cout << leaves - erased_leaves + 1 << '\n';
    }else{
        cout << leaves - erased_leaves << '\n';
    }

}