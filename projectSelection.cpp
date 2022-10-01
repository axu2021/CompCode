#include <bits/stdc++.h>
using namespace std;

bool mySort(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b){
    return(a.first.second < b.first.second);
}

int getLastJob(vector<pair<pair<int,int>, int>> &arr, int n){
    for(int i = n-1; i >= 0; i--){
        if(arr[i].first.second < arr[n].first.first){ //if ending of i is <= start of n
            return i;
        }
    }
    return -1;
}

long long getMax(vector<pair<pair<int,int>, int>> &project, int n){
    vector<long long> dp (n); // profit till project[i]
    dp[0] = project[0].second;
    for(int i = 1; i < n; i++){
        long long takeProfit = project[i].second;
        int prevProjIdx = getLastJob(project, i);
        if(prevProjIdx != -1){
            takeProfit += dp[prevProjIdx];
        }
        dp[i] = max(dp[i-1], takeProfit);
    }
    /*
    for(int i = 0; i < n-1; i++){
        cout << dp[i] << endl;
    }
    */
    return dp[n-1];
}

int main(){
    int n;
    scanf(" %d", &n);
    vector<pair<pair<int,int>, int>> project (n);
    for(int i = 0; i < n; i++){
        scanf(" %d %d %d", &project[i].first.first, &project[i].first.second, &project[i].second);
    }
    sort(project.begin(), project.end(), mySort);
    /*
    for(int i = 0; i < n; i++){
        cout << endl << project[i].first.first << " "
       <<  project[i].first.second << " "
       <<  project[i].second << endl;
    }
    */
    printf("%lld\n", getMax(project, n));
}