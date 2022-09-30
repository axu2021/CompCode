#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> coins (n+1);
    vector<long long> dp (x+1, INT_MAX);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    dp[0]=0;
    for(int i = 1; i <= n; i++){
        for(int w = 0; w <= x; w++){
            if(w - coins[i-1] >= 0){
                dp[w] = min(dp[w], dp[w-coins[i-1]]+1);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1: dp[x]) << endl;
}