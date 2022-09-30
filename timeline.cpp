#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,c;
    cin >> n >> m >> c;
    vector<int> arr (n+1);
    vector<int> indeg (n+1);
    vector<vector<pair<int,int>>> adj (n+1);
    queue<int>q;
    for(int i = 1; i <= n; i++){
        scanf(" %d", &arr[i]);
    }

    for(int i = 0; i < c; i++){
        int x,y,z;
        scanf(" %d %d %d", &x, &y, &z);
        indeg[y]++;
        adj[x].push_back({y,z});
    }
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
   
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        for(auto x: adj[curr]){
            if(--indeg[x.first] == 0){
                q.push(x.first);
            }
            arr[x.first] = max(arr[curr] + x.second, arr[x.first]);
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%d\n", arr[i]);
    }

}