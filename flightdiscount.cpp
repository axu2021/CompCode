#include <bits/stdc++.h>
using namespace std;

vector<long long> minCost(int from, vector<vector<pair<int,int>>> arr){
    vector<long long> minCost(arr.size(), INT64_MAX);
    minCost[from] = 0;
    priority_queue<pair<long long, int>> q; //price, node
    q.push({0, from});
    while(!q.empty()){
        auto currPair = q.top();
        q.pop();
        int curr = currPair.second;
        //cout << "-currPrice = " << currPair.first  << " " << curr << endl;
        if(-currPair.first != minCost[curr]){
            continue;
        }
        for(auto pair : arr[curr]){
            //cout << pair.first << " " << pair.second << endl;
            long long newCost = minCost[curr] + pair.second;
            if(newCost < minCost[pair.first]){
                minCost[pair.first] = newCost;
                q.push({-newCost, pair.first});
            }
        }
        //cout << endl;
    }
    return minCost;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> fw (n);//idx = start, pair.f = end, pair.s = price
    vector<vector<pair<int,int>>> bw (n); 
    for(int i = 0; i < m; i++){
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a, --b;
        fw[a].push_back({b,c});
        bw[b].push_back({a,c});
    }

    vector<long long> start = minCost(0, fw);
    vector<long long> end = minCost(n-1, bw);
    long long totalMin = INT64_MAX;
    for(int i = 0; i < n; i++){
        for(auto pair : fw[i]){
            if(start[i] == INT64_MAX || end[pair.first] == INT64_MAX){
                continue;
            }
            totalMin = min(totalMin, start[i] + (pair.second/2) + end[pair.first]);
        }
    }
    cout << totalMin<< endl;
}