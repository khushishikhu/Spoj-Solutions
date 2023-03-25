#include <iostream>
#include <bits/stdc++.h>
int INF = 1 << 30;
using namespace std;
#define ll long long 
 
 
ll num=0;
void dfs(vector<vector<ll> > &v,ll x,ll y){
  
 ll n=v.size();
 ll m=v[0].size();
 
  if(x<0 || x>=n || y<0 || y>=n || v[x][y]==0){
    return;
  }
  v[x][y]=0;
  num++;
  dfs(v,x-1,y);
  dfs(v,x+1,y);
  dfs(v,x,y-1);
  dfs(v,x,y+1);
  
}
int main() {
 
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
while(1){
ll n,m;
cin>>n>>m;
if(n==0 && m==0){
break;
}
vector<vector<ll>> v(n+1,vector<ll>(m+1,0));
 
for(ll i=0;i<n;i++){
  for(ll j=0;j<m;j++){
   ll x;
    cin>>x;
    v[i][j]=x;
  }
}
 
ll cnt=0;
// priority_queue<pairll>,vector<pairll>>, greater<pairll>>> pq;
map<ll,ll> mp;
for(ll i=0;i<n;i++){
  for(ll j=0;j<m;j++){
 
    if(v[i][j]!=0){
      cnt++;
      num=0;
      dfs(v,i,j);
      mp[num]++;
    }
  }
}
 
cout<<cnt<<endl;
for(auto i:mp){
  cout<<i.first<<" "<<i.second<<endl;
}
 
}
 
 
  cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
return 0;
 
}
 