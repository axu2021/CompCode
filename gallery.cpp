#include <cstdio>
#include <iostream>
#include <vector>  
#include <algorithm>  
using namespace std; 
#define N 600
int dp[N][N];  
int id=0,x,y,s;  
struct node  
{  
    int t,l,r;  
    int v;  
};

node tree[N];
void init(int now)  
{
    scanf("%d%d",&x,&y);  
    tree[now].t=x*2;
    tree[now].v=y;

    if(y!=0) tree[id].l=tree[id].r=-1;

    else  
    {  
        tree[now].l=++id;init(id); // l branch points to index of child
        tree[now].r=++id;init(id); // r branch points to index of child
    }  
}  
int dfs(int now,int times)  
{ //now - the number of the current edge, time = time for previous iteration
    if(dp[now][times]) return dp[now][times];  
    int remainT=times-tree[now].t;
    if(remainT<0) return 0;  
    if(tree[now].l==-1) return dp[now][times]=min(tree[now].v,remainT/5);
    int maxn=0; 
    for(int i = 0; i <= remainT; i++)  //with remain time, find max v on l,r branch
    {  
        maxn=max(maxn, dfs(tree[now].l,i)+dfs(tree[now].r,remainT-i) ); 
    }  
    return dp[now][times]=maxn;
}  
int main()  
{  
    scanf("%d",&s);  
    init(0);  
    printf("%d\n",dfs(0,s));  
    return 0;  
}  
