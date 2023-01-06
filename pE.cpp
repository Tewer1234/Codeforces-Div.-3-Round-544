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
int cover[1000000];
int dp[5005][5005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,k;
  cin>>n>>k;
  for (int i=0;i<n;i++) cin>>ary[i];
  
  sort(ary,ary+n);
  for (int i=0;i<n;i++){
    int l,r,mid,dif,temp=-1;
    l=i,r=n-1;
    // cout<<l<<" "<<r<<"\n";
    while (l<=r){
      mid=(l+r)/2;
      dif=ary[mid]-ary[i];
      if (dif<=5){
        temp=mid;
        l=mid+1;
      }else{
        r=mid-1;
      }
    }
  
    if (temp==-1){
      cover[i]=1;
    }else{
      cover[i]=temp-i+1;
    }
  }
  
  
  // for (int i=0;i<n;i++) cout<<ary[i]<<" "<<cover[i]<<"\n";
  // cout<<"\n";

  int ans=0;
  // dp[1][1]=cover[1];
  for (int i=0;i<n;i++){
    for (int j=0;j<=k;j++){
      dp[i+1][j]=max(dp[i][j],dp[i+1][j]);
      if (j+1<=k){
        dp[i+cover[i]][j+1]=max(dp[i+cover[i]][j+1],dp[i][j]+cover[i]);
      }
    }
  }
  
  for (int i=1;i<=n;i++){
    for (int j=0;j<=k;j++){
      // cout<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
      ans=max(ans,dp[i][j]);
    }
  }
  
  cout<<ans;
  return 0; 
}
