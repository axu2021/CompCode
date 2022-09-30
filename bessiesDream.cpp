#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int n,m;

bool isPathable(int x, int y, int smellsNice, vector<vector<int>> &tile) {
    if (x < 0 || x >= m || y < 0 || y >= n) return false;
    if (tile[y][x] == 0) return false;
    if (tile[y][x] == 3) return (smellsNice > 0);
    
    return true;
}

int main(){
    scanf(" %d %d", &n, &m);
    vector<vector<int>> arr (n, vector<int> (n));
    vector<vector<vector<int>>> visit (n, vector<vector<int>>(n, vector<int>(2)));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %d", &arr[i][j]);
            visit[i][j][0] = visit[i][j][1] = 100000000;
        }
    }
    priority_queue<pair<int, pair<int, pair<int, int>>>> q;
    q.push({0,{0,{0,0}}});
    while(!q.empty()){
        auto p = q.top();
        q.pop();
        int dist = p.first;
        int x = p.second.first;
        int y = p.second.second.first;
        int sm = p.second.second.second;
        if(x == m-1 && y == n-1){
            cout << dist << endl;
            return 0;
        }
        if (visit[y][x][sm] != 100000000) {
            continue;
        }
        visit[y][x][sm] = dist;
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            int nd = dist+1;
            int nsm = sm;
            if(!isPathable(nx, ny, sm, arr)) continue;
            if(arr[ny][nx] == 4){
                while((isPathable(nx+dx[i],ny +dy[i], sm, arr)) && arr[ny][nx] == 4){
                    nx += dx[i];
                    ny += dy[i];
                    nd++;
                    nsm = 0;
                }
            }
            if(arr[ny][nx] == 2){
                nsm = 1;
            }
            if(visit[ny][nx][nsm] <= nd){continue;}
            q.push({nd,{nx,{ny,nsm}}});
        }
    }
    cout << -1 << endl;
}