#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<bool>> traps (n+1, vector<bool> (n+1,false));
    vector<vector<int>> dp (n+1, vector<int> (n+1));
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        traps[x][y] = true;
    }
   if(traps[1][1]){
    cout << 0 << endl;
    return 0;
   }
   dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(traps[i][j]){
                continue;
            }
            dp[i][j] += (dp[i-1][j] + dp[i][j-1])%MOD;
        }
    }
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[n][n] << endl;
}