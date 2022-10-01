#include <bits/stdc++.h>
using namespace std;
int n, w;

int main(){
    cin >> n >> w;
    vector<int> arr (n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int end = 1 << n;
    vector<pair<long long, long long>> dp(end); // num rides, weight of last ride
    dp[0] = {1,0};
    for(int mask = 1; mask < end; mask++){
        pair<long long, long long> best = {INT_MAX, INT_MAX};
        for(int i = 0; i < n; i++){
            if (((1 << i) & mask) == 0) continue;  // if the number not the overlapping bits
            auto res = dp[(1 << i) ^ mask];
            if(res.second + arr[i] <= w){
                res.second += arr[i];
            }
            else{
                res.first++;
                res.second = arr[i];
            }
            best = min(best, res);
        }
        dp[mask] = best;
    }
    cout << dp[end-1].first << endl;
}