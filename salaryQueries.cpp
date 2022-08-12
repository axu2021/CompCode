#include <bits/stdc++.h>
using namespace std;

const int LMT = 4e5+5;
vector<long long> BIT (LMT), vals;
int n,q;

void update(int idx, int val){
    while(idx <= LMT){
        BIT[idx] += val;
        idx += (idx & -idx);
    }
}

void ad(int x, int b) {
    //cout << " x = " << x << " ";
	int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
    //cout << "idx = " << ind << endl;
    update(ind, b);
}

long long read(int idx){
    long long sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

long long query(int x) {
	int ind = upper_bound(vals.begin(), vals.end(), x) - vals.begin();
	return read(ind);
}

int main(){
    cin >> n >> q;
    vector<long long> arr (n);
    for(int i = 0; i < n; i++){
        scanf(" %lld", &arr[i]);
    }
    vals = arr;
    vector<array<int, 3>> rec;
    for (int i = 0; i < q; i++) {
		char t;
		int a,b;
		scanf(" %c", &t);
        scanf( " %d %d", &a, &b);
		rec.push_back({t == '?', a, b}); // bool, int, int
		if (t == '!') vals.push_back(b);
	}
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end()); // remove repeats

    for (int i = 0; i < n; i++) {
		ad(arr[i], 1);
	}

    for (auto u : rec) {
		u[1]--; //indexing 0
        //cout << "u[1] = " << u[1] << endl;
		if (u[0] == 0) { //if qt = !
			ad(arr[u[1]], -1); //remove 1 feq
			arr[u[1]] = u[2]; //change idx to new val
			ad(arr[u[1]], 1); //add 1 feq
		} else {
			printf("%lld\n", query(u[2]) - query(u[1]));
		}
	}
}