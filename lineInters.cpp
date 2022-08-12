#include <bits/stdc++.h>

using namespace std;

struct line{
    pair<int,int> p1,p2;
    int event;
};

bool mySort(line a, line b){
    return(a.p1.first < b.p1.first);
}
int idx;
vector<int> tree (2000005);


void update(int idx, int val){
    while(idx <= tree.size()){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

long read(int idx) {
  long sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

long findInt(vector<line> &arr){
    long ans = 0;
    for(int i = 0; i < idx; i++){
        line l = arr[i];
        if(l.event == 0) update(l.p1.second + 1000001, 1); // add y
        else if(l.event == 1) update(l.p1.second + 1000001, -1); //remove y
        else{
            //auto itlow = lower_bound(mySet.begin(), mySet.end(), l.p1.second);
            //auto ithigh = upper_bound(itlow, mySet.end(), l.p2.second);
            long y1 = read(l.p1.second + 1000001), y2 = read(l.p2.second + 1000001);
            ans += abs(y1-y2);
            //ans += (*itlow - *ithigh );
        }
    }
    return ans;
}

int main(){
    ifstream fin("input.txt");
    int n;
    fin >> n;
    int x1,y1,x2,y2;
    vector<line> arr (n*2);
    for(int i = 0; i < n; i++){
        fin >> x1 >> y2 >> x2 >>y2;
        //scanf("%d %d %d %d", &x1, &y1,&x2, &y2);
        if(x1 == x2){
            arr[idx].p1 = make_pair(x1,y1);
            arr[idx].p2 = make_pair(x2,y2);
            arr[idx].event = 2;
            idx++;
        }
        else{
            arr[idx].p1 = make_pair(x1,y1);
            arr[idx].p2 = make_pair(x2,y2);
            arr[idx].event = 0;
            idx++;
            
            arr[idx].p1 = make_pair(x2,y2);
            arr[idx].p2 = make_pair(x1,y1);
            arr[idx].event = 1;
            idx++;
        }
    }
    cout << "Idx = " << idx << endl;
    sort(arr.begin(), arr.begin()+idx, mySort);   
    cout << arr[0].p1.first << " " << arr[0].p1.second  << " " << arr[0].p2.first << " " << arr[0].p2.second << endl;

    cout << findInt(arr) << endl;
    
}

/*
3
6 2 6 6
2 3 7 3
3 1 3 5
*/