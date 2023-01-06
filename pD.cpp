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
typedef pair<int,char> pp;
int ary[1000000],bry[1000000];
int num[1000000],den[1000000];
int check[1000000];
int gcd(int a,int b){
  int t;
  while (b!=0){
    t=b;
    b=a%b;
    a=t;
  }
  return a;
}
string create(int num){
  string t="";
  while (num){
    char c=(num%10)+'0';
    // cout<<c;
    t=c+t;
    num/=10;
  }
  return t;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  map <string,int> mp;
  cin>>n;
  for (int i=1;i<=n;i++) cin>>ary[i];
  for (int i=1;i<=n;i++) cin>>bry[i];
  
  for (int i=1;i<=n;i++){
    num[i]=-(bry[i]);
    den[i]=ary[i];
    if (ary[i]!=0){
      int g=gcd(num[i],den[i]);
      num[i]/=g;
      den[i]/=g;
      check[i]=1;
    }
  }
  
  for (int i=1;i<=n;i++){
    if (check[i]){
      string tt1=create(abs(num[i]))+" / ";
      string tt2=create(abs(den[i]));
      if (num[i]<0) tt1="-"+tt1;
      if (den[i]<0) tt2="-"+tt2;
      string final=tt1+tt2;
      mp[final]++;
      // cout<<"D: "<<final<<"\n";
    }else if (!num[i] and !den[i]){
      mp["0 / 0"]++;
    }
  }
  
  int ans=INT_MIN,add=0;
  for (auto it:mp){
    if (it.first=="0 / 0") add+=it.second; 
    else if (it.second>ans) ans=it.second;
  }
  
  if (ans==INT_MIN and !add) cout<<0;
  else{
    if (ans>0) cout<<ans+add;
    else cout<<add;
  }
  
  return 0; 
}
