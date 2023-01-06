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
int comp[1000000];
int used[SIZE];
int Cone[SIZE];
int check[SIZE];
vector <int> p;
vector <int> nodes[SIZE];
void dfs(int n,int c){
  int nxt;
  for (int i=0;i<nodes[n].size();i++){
    nxt=nodes[n][i];
    if (nxt!=1 and !comp[nxt]){
      comp[nxt]=c;
      dfs(nxt,c);
    }
  }
}
void dfs1(int n){
  int nxt;
  for (int i=0;i<nodes[n].size();i++){
    nxt=nodes[n][i];
    if (nxt!=1 and !used[nxt]){
      used[nxt]=1;
      cout<<n<<" "<<nxt<<"\n";
      dfs1(nxt);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m,d,x,y,cone=0;
  cin>>n>>m>>d;
  for (int i=1;i<=m;i++){
    cin>>x>>y;
    nodes[x].pb(y);
    nodes[y].pb(x);
    if (x==1) cone++,Cone[y]++;
    else if (y==1) cone++,Cone[x]++;
  }
  
  int cnt=0;
  for (int i=2;i<=n;i++){
    if (!comp[i]){
      cnt++;
      comp[i]=cnt;
      dfs(i,cnt);
    }
  }
  
  
  if (cnt>d or d>cone) cout<<"NO";
  else{
    cout<<"YES\n";
    for (int i=2;i<=n;i++){
      if (!check[comp[i]] and Cone[i]){
        check[comp[i]]=1;
        used[i]=1;
        cout<<1<<" "<<i<<"\n";
        p.pb(i);
        d--;
      }
      
      if (!d) break;
    }
    
    for (int i=2;i<=n;i++){
      if (!used[i] and Cone[i]){
        used[i]=1;
        cout<<1<<" "<<i<<"\n";
        p.pb(i);
        d--;
      }
      if (!d) break;
    }
    used[1]=1;
    for (int i=0;i<p.size();i++){
      dfs1(p[i]);
    }
  }
  return 0; 
}
