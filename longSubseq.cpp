#include <bits/stdc++.h>
using namespace std;

int n;

void init(int i, int a, int b, vector<int> &lo, vector<int> &hi){
  lo[i] = a;
  hi[i] = b;
  if(a==b){ // leaf
    return;
  }
  int m = (a+b)/2;
  init(2*i, a, m, lo, hi);
  init(2*i+1, m+1, b, lo, hi);
}

int query(int pos, int l, int r, vector<int> &tree, vector<int> &lo, vector<int> &hi){
  int high = hi[pos], low = lo[pos];

  if(low >= l && high <= r) return tree[pos]; // fully contain

  if(l > high || r < low) return 0; //not contained

  return(max(query(pos*2, l, r, tree, lo, hi),
            query(pos*2+1, l, r, tree, lo, hi))); // partly
}

void update(vector<int> &tree, int pos, vector<int> &lo, vector<int> &hi){
  int currMax = query(1, 1, pos, tree, lo, hi);
  //cout << "currMax = " << currMax  << " pos = " << pos << endl;
  pos += pow(2, ceil(log2(n)));
  //cout << "idx = " << pos << endl;
  tree[pos] = currMax + 1;  
  for(int i = pos; i >= 1; i/=2){
    tree[i] = max(tree[i], tree[pos]);
  }
}

void build(vector<int> &tree, vector<int> &arr,  map<int, int> &compressCord, vector<int> &lo, vector<int> &hi){
  for(int i = 1; i <= n; i++){
    auto it = compressCord.find(arr[i]);
    int pos = it->second;
    //cout << arr[i] << " pos = " << pos << endl;
    update(tree, pos, lo, hi);
  }
}

int main() {
  cin >> n;
  vector<int> tree (4*n+1), lo(4*n+1), hi(4*n+1);
  vector<int> arr (n+1);
  map<int, int> compressCord;
  for(int i = 1; i <= n; i++){
    cin >> arr[i];
  }
  vector<int> temp;
  temp = arr;
  sort(temp.begin(), temp.end());
  int idx = 1;
  for(int i = 1; i <= n; i++){
    if(compressCord.count(temp[i]) == 0){
      compressCord.insert({temp[i], idx++});
    } 
  }
  //cout << "num = " << pow(2, ceil(log2(n))) << endl;
  init(1, 1, pow(2, ceil(log2(n))), lo, hi);
  /*
  for(int i = 1; i <= 2*n; i++){
    cout << "i = " << i << " lo = " << lo[i] << " hi = " << hi[i] << endl;
  }
  */
  build(tree, arr, compressCord, lo, hi);
  cout << tree[1];
} 