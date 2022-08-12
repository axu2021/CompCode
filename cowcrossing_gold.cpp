#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 0, -1, 0, 3, 0, -3, 0, 2, 2, 1, 1, -1, -1, -2, -2};
int dy[] = {0, 1, 0, -1, 0, 3, 0, -3, 1, -1, 2, -2, 2, -2, 1, -1};


int main(){
    int n, t;
    cin >> n >> t;
    vector<vector<int>> arr(n, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dist (n, vector<int> (n, INT_MAX));
    dist[0][0] = 0;
    vector<vector<bool>> visit(n, vector<bool>(n));
    priority_queue<pair<int,pair<int,int>>> q; // {dist, {x,y}}
    q.push({0,{0,0}});
    int ans = INT_MAX;
    while(!q.empty()){
        int x = q.top().second.first, y = q.top().second.second;
        q.pop();
        if(visit[x][y]){continue;}
        visit[x][y] = true;
        for(int i = 0; i < 16; i++){
            int newX = x + dx[i], newY = y+dy[i];
            if(newX <0 || newX >= n || newY < 0 || newY >= n){continue;}
            if(dist[newX][newY] > dist[x][y] + (3*t) + arr[newX][newY]){
                dist[newX][newY] = dist[x][y] + (3*t) + arr[newX][newY];
                q.push({-dist[newX][newY],{newX,newY}});
            }
        }

        int finalD = n-x-1+n-y-1;
        if(finalD < 3){
            dist[n-1][n-1] = min(dist[n-1][n-1], dist[x][y] + (finalD*t));
        }
    }
    cout << dist[n-1][n-1] << endl;
}