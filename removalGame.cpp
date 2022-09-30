#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> arr (n);
    vector<vector<long long>> diff (n, vector<long long> (n));
    long long totalsum = 0;
    for(int i = 0;i < n; i++){
        cin >> arr[i];
        diff[i][i] = arr[i];
        totalsum += arr[i];
    }
    for(int l = n-1; l >= 0; l--){
        for(int r = l+1; r < n; r++){
            long long takeLeft =  arr[l] - diff[l + 1][r]; 
            long long takeRight = arr[r] - diff[l][r-1];
            diff[l][r] = max(takeLeft, takeRight);
        }
    }
    cout << (totalsum + diff[0][n-1])/2;
}