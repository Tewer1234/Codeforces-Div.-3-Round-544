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
int rem[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  for (int i=1;i<=n;i++) rem[ary[i]%m]++;
  
  int ans=rem[0]/2,pos=m-1;
  if (!(m%2)) ans+=(rem[m/2]/2);
  for (int i=1;i<(m+1)/2;i++){
    ans+=min(rem[i],rem[pos]);
    pos--;
  }
  
  ans*=2;
  cout<<ans;
  return 0; 
}
