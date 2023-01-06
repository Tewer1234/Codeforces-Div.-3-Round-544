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
  int h1,h2,m1,m2;
  string s,t;
  cin>>s>>t;
  h1=h2=m1=m2=0;
  h1=(s[0]-'0')*10+(s[1]-'0');
  h2=(t[0]-'0')*10+(t[1]-'0');
  m1=(s[3]-'0')*10+(s[4]-'0');
  m2=(t[3]-'0')*10+(t[4]-'0');
  
  int t1=h1*60+m1;
  int t2=h2*60+m2;
  int t3=(t1+t2)/2;
  cout<<setw(2)<<setfill('0')<<t3/60<<":"<<setw(2)<<setfill('0')<<t3%60;
  return 0; 
}
