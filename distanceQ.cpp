#include <bits/stdc++.h>
using namespace std;

//vector<vector<int>> lift (20, vector<int> (200005));
int lift[200005][20];
vector<int> depth(200005);
vector<int> adj [200005];
int n,q;

void dfs(int x){
    for(int i = 1; i < 20; i++){
        lift[x][i] = lift[ lift[x][i-1] ][i-1];
    }
    for(int e : adj[x]){
        if(e != lift[x][0]){ //node e is child
            lift[e][0] = x;
            depth[e] = depth[x]+1;
            dfs(e);
        }
    }
}

int jump(int x, int d){
    for(int i = 0; i < 20; i++){
        if((d>>i)&1){
            x=lift[x][i];
        }
    }
    return x;
}

int lca(int a, int b){
    if(depth[a] < depth[b]){
        swap(a,b);
    }
    a = jump(a, depth[a]-depth[b]);
    if(a == b) return a;
    for(int i = 19; i >= 0; i--){
        if(lift[a][i] != lift[b][i]){
            a = lift[a][i]; b = lift[b][i];
        }
    }
    return lift[a][0];
}

int main(){
    scanf(" %d %d", &n, &q);
    for(int i = 0; i < n-1; i++){
        int a,b;
        scanf(" %d %d", &a , &b); 
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    lift[0][0] = 0; // i = node i, j = 2^j ancestor
    depth[0] = 0; // level in tree
    dfs(0);


    for(int i = 0; i < q; i++){
        int a,b;
        scanf(" %d %d", &a , &b); 
        --a; --b;
        printf("%d\n", depth[a] + depth[b] - 2*depth[lca(a,b)]);
        //cout << depth[a] + depth[b] - 2*depth[lca(a,b)] << endl;
    }
}