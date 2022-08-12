#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define HA 100000007
#define HB 273


long long getHash(long long h, char c){
    return (h * HA + c + HB) % mod;
}

int main(){
    string s,t;
    cin >> s >> t;
    long long tHash = 0;
    for(int i = 0; i < t.size(); i++){
        tHash = getHash(tHash, t[i]-'a');
    }
    string ans;
    vector<long long> ansHash(1);
    vector<long long> hashPow(1,1);
    for(int i = 0; i < s.size(); i++){
        ans += s[i];
        ansHash.push_back(getHash(ansHash.back(), s[i]-'a'));
        hashPow.push_back((hashPow.back() * HA) % mod);

        if(ans.size() >= t.size()){
            int hsub = (1ll * ansHash[ans.size() - t.size()] * hashPow[t.size()]) % mod;
            int hsh = (mod + ansHash.back() - hsub) % mod;

            if (hsh == tHash && ans.substr(ans.size() - t.size()) == t) {
                ans.resize(ans.size() - t.size());
                ansHash.resize(ansHash.size() - t.size());
                hashPow.resize(hashPow.size() - t.size());
            }
        }
    }
    cout << ans << endl;
    return 0;
}