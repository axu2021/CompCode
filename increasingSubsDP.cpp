#include <bits/stdc++.h>
using namespace std;

int arr[200001], dp[200001];


int findLIS(vector<int>& arr, int n){
    int mx = 0;
    dp[0]=1;
    for(int i = 1; i < n; i++){
        dp[i]=1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        mx = max(dp[i], mx);
    }
    return mx;
}


int main(){
    int n;
    scanf(" %d", &n);
    if(n <= 1)
    {
        printf("%d\n" , n);
        return 0;
    }
    vector<int> arr (n);
    for(int i = 0; i < n; i++){
       scanf(" %d", &arr[i]);
    }
    printf("%d\n" , findLIS(arr, n));
}