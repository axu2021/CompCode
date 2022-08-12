#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<long> BIT (4*200005);
long n,q;

void update(long idx, long val){
    while(idx <= MAXN){
        BIT[idx] += val;
        idx += (idx & (-idx));
    }
}

long read(long idx){
    long sum = 0;
    while (idx > 0) {
        sum += BIT[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int main(){
    scanf(" %ld", &n);
    int ans = 0;
    unordered_map<int,int> mp; //num, idx
    for(long i = 1; i <= 2*n; i++){
        int num;
        scanf(" %ld", &num);
        //cout << "mp " << num <<  " = " << mp.find(num)->second << endl;
        if(mp.count(num) == 0){
            mp[num] = i;
            update(i, 1);
        }
        else{
            update(mp[num], -1); update(i, 0);
            long l = read(mp[num]), r = read(i-1);
            //printf("l=%ld, r=%ld\n", l, r);
            ans += r-l;
            //printf("ans = %ld\n", r-l);
        }
    }
    cout << ans << endl;
}