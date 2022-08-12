#include <bits/stdc++.h>
using namespace std;

vector<long long> BIT (4*200005);
long long n;

bool mySort(pair<int,int> a, pair<int,int> b){
    return(b.first < a.first);
}

void update(long long idx, long long val){
    while(idx <= n){
        BIT[idx] += val;
        idx += (idx & (-idx));
    }
}

long long read(long long idx){
    long long sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int main(){
    cin >> n;
    vector<pair<int,int>> arr (n);
    for(int i = 0; i < n; i++){
        int num;
        scanf(" %d", &num);
        arr[i].first = num;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end(), mySort);
    int ret = 0, seen = 0;
    for(auto x : arr){
        //cout << "x = " << x.first << " idx = " << x.second+1 <<" seen = " << seen << " ret = " << ret << endl;
        int lhs = read(x.second+1);
        int rhs = seen-lhs;
        //cout << "l = " << lhs << " rhs = " << rhs << endl;
        if(max(lhs,rhs) > 2*min(lhs, rhs)) ret++;
        update(x.second+1, 1);
        seen++;
    }
    cout << ret;
}