#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9+7;
const int base = 273;
const int maxN = 1e6+6;

vector<long long> pre (maxN);
vector<long long> suf (maxN);
long long n,m;

void update(long long idx, long long val, vector<long long> &BIT){
    val %= mod;
    if(val < mod) val += mod;
    while(idx <= n){
        (BIT[idx] += val) %= mod;
        idx += (idx & (-idx));
    }
}

long long read(long long idx, vector<long long> &BIT){
    long long sum = 0;
    while (idx > 0) {
        (sum += BIT[idx]) %= mod;
        idx -= (idx & (-idx));
    }
    return sum;
}


int main(){
    cin >> n >> m;
    string s;
    cin >> s;
    vector<long long> primeB (1e6+6);
    primeB[0] = 1;
    for (int i = 1; i < maxN; i++){
        primeB[i] = primeB[i-1] * base % mod;
    }
    for(int i = 0; i < n; i++){
        update(i+1, (s[i]-'a'+1) * primeB[i], pre);
        update(i+1, (s[i]-'a'+1) * primeB[n-i-1], suf);
    }

    for(int i = 0; i < m; i++){
        int k;
        scanf(" %d", &k);
        if(k == 1){
            int k; char x;
            scanf(" %d %c", &k, &x);
            k--;
            update(k+1, -(s[k]-'a'+1) * primeB[k], pre); // subtract
            update(k+1, (x-'a'+1) * primeB[k], pre); // add
            update(k+1, -(s[k]-'a'+1) * primeB[n-k-1], suf); 
            update(k+1, (x-'a'+1) * primeB[n-k-1], suf); 
            s[k] = x; 
        }
        else{
            int x, y; scanf(" %d %d", &x, &y);
            long long h1 = (read((x+y)/2, pre) - read(x-1, pre) + mod) % mod;
            long long m1 = primeB[x-1];
            long long h2 = (read(y, suf) - read((x+y-1)/2, suf)+mod) % mod;
            long long m2 = primeB[n-y];
            if(h1 * m2 % mod == h2 * m1 % mod ){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
}
