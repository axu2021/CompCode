#include <bits/stdc++.h>
using namespace std;
 
int findLIS(vector<int>& arr, int n){
    vector<int> lis;
 
    for(int i = 0; i < n; i++){
        auto it = lower_bound(lis.begin(), lis.end(), arr[i]);
        if (it != lis.end()) {
           *it = arr[i];
        } else {
            lis.push_back(arr[i]);
        }
    }
    return lis.size();
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