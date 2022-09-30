#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, MOD = 1e9 + 7;;
    cin >> n >> x;
    vector<int> coins (n);
    vector<long long> dp (x+1,0); // comb. of coins to form i
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    dp[0]=1;
    for(int weight = 0; weight <=x; weight++){
        for(auto v : coins){
            if(weight-v >= 0) {
                dp[weight]+=dp[weight-v];
                dp[weight]%=MOD;
            }
        }
    }
    cout << dp[x] << endl;
}