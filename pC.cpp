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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  
  sort(ary+1,ary+n+1);
  // for (int i=1;i<=n;i++) cout<<i<<": "<<ary[i]<<"\n";
  int dif,ans=0;
  for (int i=1;i<=n;i++){
    int l=i,r=n,mid,temp=-1;
    while (l<=r){
      mid=(l+r)/2;
      if (ary[mid]<=ary[i]+5){
        temp=mid;
        l=mid+1;
      }else r=mid-1;
    }
    if (temp!=-1){
      ans=max(ans,temp-i+1);
    }
  }
  
  cout<<ans;
  return 0; 
}
