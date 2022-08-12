#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(){
    string s;
    cin >> s;
    int n;
    cin >> n;
    map<int,set<string>> mymap;
    for(int i = 0; i < n; i++){
        string pat;
        cin >> pat;
        mymap[pat.size()].insert(pat);
    }
    for(int i = 0; i < s.size(); i++){
        
    }
}