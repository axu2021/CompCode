#include <bits/stdc++.h>
using namespace std;
vector<int> mem (1000000,-1);

int encode(int a, int b){
    return min(a,b)*1000 + max(a,b);
}

int search(int a, int b){
    //cout << a << " " << b << endl;
    int key = encode(a,b);
    //cout << "key - " << key << endl;
    if(mem[key] >= 0){
        //cout << "found = " << mem[key] << endl;
        return mem[key];
    }
    int count = INT_MAX, small = min(a,b), big = max(a,b);
    //cout << "s = " << small << " b = " << big << endl;
    for(int i = 1; i <= big/2; i++){
        int currC = search(i,small) + search(big-i, small) + 1;
        count = min(currC, count);
    }
    for(int i = 1; i <= small/2; i++){
        int currC = search(i,big) + search(small-i, big) + 1;
        count = min(currC, count);
    }
    mem[key] = count;
    return count;
}

int main(){
    int a,b;
    cin >> a >> b;
    for(int i = 1; i<=500; i++){
        mem[1000*i+i] = 0;
        mem[1000+i] = i-1;
    }
    cout << search(a,b);
}