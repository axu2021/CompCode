#include <bits/stdc++.h>
using namespace std;

vector<long> BIT (4*200005);
long n,q;

void update(long idx, long val){
    while(idx <= n){
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
    scanf(" %ld %ld", &n, &q);
    vector<long> val (n+1);
    for(long i = 1; i <= n; i++){
        scanf(" %ld", &val[i]);
        update(i, val[i]);
    }

    for(long i = 0; i < q; i++){
        long a,b,c;
        scanf(" %ld %ld %ld", &a, &b, &c);
        if(a == 1){
            long diff = c-val[b];
            update(b, diff);
            val[b] = c;
        }
        else{
            long l = read(b-1), r = read(c);
            printf("%ld\n", r-l);
        }
    }
}