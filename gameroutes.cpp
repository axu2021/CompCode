#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> indeg (n+1, 0);
    vector<vector<int>> edge (100001);
    vector<vector<int>> edgeB (100001);
    vector<int> dp (n+1, 0);
    priority_queue<int, vector<int>, greater<int>>q;
    for(int i = 0; i < m; i++){
        int a,b;
        scanf(" %d %d", &a, &b);
        indeg[b]++;
        edge[a].push_back(b);
        edgeB[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    dp[1] = 1;
    while(!q.empty()){
        int curr = q.top();
        q.pop();
        for(auto x : edge[curr]){
            indeg[x]--;
            if(indeg[x] == 0){
                q.push(x);
            }
        }
        for(auto x : edgeB[curr]){
            dp[curr] = (dp[curr] + dp[x]) % 1000000007;
        }
        
    }
    cout << dp[n] << endl;
}