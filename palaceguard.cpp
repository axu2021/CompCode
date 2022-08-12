#include <bits/stdc++.h>
using namespace std;
const int lmt = 1505;
int n;
int w[lmt];
vector<vector<int>> tree (lmt);
//3 states 0 means that the parent node has placed a guard, 1 means that the child node has placed a guard, 2 means that it has placed a guard
int dp[lmt][3];
bool vis[lmt];


void dfs(int u){
	if(dp[u][0]) return;
	dp[u][2] = w[u];
	for(auto j : tree[u]){
		dfs(j);
		dp[u][0] += min(dp[j][1], dp[j][2]);
		dp[u][2] += min(min(dp[j][0], dp[j][1]), dp[j][2]);
	}
	dp[u][1] = 1e9;
	for(auto j : tree[u]){
		dp[u][1] = min(dp[u][1], dp[j][2]+dp[u][0]-min(dp[j][1], dp[j][2]));
	}
}

int main(){
	scanf(" %d", &n);
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++){
		int id, cost, cnt;
		scanf(" %d %d %d", &id, &cost, &cnt);
		w[id] = cost;
		while(cnt--){
			int child;
			scanf(" %d", &child);
			tree[id].push_back(child);
			vis[child] = true;
		}
	}
	int root = 1;
	while (vis[root]) root++; // find root node
	dfs(root);

	cout << min(dp[root][1], dp[root][2]) << endl;
}
