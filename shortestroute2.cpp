#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector<long long>>dis (n, vector<long long> (n,1e18));
    for(int i = 0; i < m; i++){
        int a,b,w;
        cin >> a >> b >>w;
        a--;b--;
        if(w < dis[a][b]){
            dis[a][b] = dis[b][a] = w;
        }
    }
    
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
               dis[i][j] = min(dis[i][j],(dis[i][k]+dis[k][j]));
            }
        }
    }


    for(int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if (a == b) dis[a][b] = 0;
		if (dis[a][b] == 1e18) dis[a][b] = -1;
		cout << dis[a][b] << "\n";
    }
}