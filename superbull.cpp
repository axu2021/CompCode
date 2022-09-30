#include <bits/stdc++.h>
using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

struct Edge{
    long long x,y,w;
};

bool mySort(Edge a, Edge b){
    return a.w > b.w;
}

int main(){
    int n;
    cin >> n;
    DSU dsu(n);
    vector<long long> x (n);
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    vector<Edge> edges;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            long long d = x[i] ^ x[j]; 
            edges.push_back({i,j,d});
        }
    }
    sort(edges.begin(), edges.end(), mySort);

    long long ans = 0, remaining = n;
    for(auto e: edges){
        if(!dsu.same_set(e.x, e.y)){
            dsu.unite(e.x, e.y);
            ans += e.w;
            if(--remaining == 1){
                break;
            }
        }
    }
    cout << ans << endl;
}