#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <bits/stdc++.h>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long int 
#define pb push_back
#define inf 0x3f3f3f3f
#define SIZE 400005
using namespace std;
typedef pair<int,int> pp;
int ary[1000000];
int deg[1000000];
int num[1000000];
int used[1000000];
vector <int> nodes[1000000];
void dfs(int n){
  for (int i=0;i<nodes[n].size();i++){
    int nxt=nodes[n][i];
    if (!used[nxt]){
      used[nxt]=1;
      cout<<n<<" "<<nxt<<"\n";
      dfs(nxt);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,x,y;
  cin>>n>>m;
  for (int i=1;i<=m;i++){
    cin>>x>>y;
    nodes[x].pb(y);
    nodes[y].pb(x);
    deg[x]++;
    deg[y]++;
  }
  
  int node,cnt=0;
  for (int i=1;i<=n;i++){
    if (cnt<deg[i]){
      cnt=deg[i];
      node=i;
    }
  }
  
  int amount=0;
  used[node]=1;
  for (int i=0;i<min(n-1,cnt);i++){
    cout<<node<<" "<<nodes[node][i]<<"\n";
    int t=nodes[node][i];
    amount++;
    num[amount]=t;
    used[t]=1;
  }
  
  
  for (int i=1;i<=amount;i++){
    dfs(num[i]);
  }
  return 0; 
}
