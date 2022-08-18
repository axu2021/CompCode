#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> indeg (n, 0);
    vector<vector<int>> edge (n, vector<int> (100000));
    priority_queue<int>q;
    for(int i = 0; i < m; i++){
        int a,b;
        scanf(" %d %d", &a, &b);
        a--;b--;
        indeg[b]++;
        edge[a].push_back(b);
    }
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int curr = q.top();
        ans.push_back(curr);
        q.pop();
        for(auto x : edge[curr]){
            indeg[x]--;
            if(indeg[x] == 0){
                q.push(x);
            }
        }
    }
    if(ans.size() != n){
        cout << "IMPOSSIBLE" << endl;
    }
    for(int i = 0; i < n; i++){
        cout << ans[i]+1 << " ";
    }
}