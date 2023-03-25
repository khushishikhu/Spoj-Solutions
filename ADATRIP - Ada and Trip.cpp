#include <iostream>
#include <bits/stdc++.h>
int INF = 1 << 30;
using namespace std;
 
pair<int,int> res[500010];
bool vis[500010];
int dist[500010];
 
 
pair<int,int> dijkastra(int node,int n,vector<vector<pair<int,int>>> adj){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
  int tot=0;
  int further = -1;
  pq.push({0,node});
  for (int i = 0; i <= n; i++)
      dist[i] = INF;
  dist[node]=0;
  pair<int,int> curr;
 
  while(!pq.empty()){
    curr=pq.top();
    pq.pop();
    if(dist[curr.second]<curr.first)continue;
    if(curr.first>further){
      further=curr.first;
      tot=1;
    }
    else{
      tot++;
    }
    for(auto x:adj[curr.second]){
      if(curr.first+x.second < dist[x.first]){
        dist[x.first]=curr.first+x.second;
        pq.push({dist[x.first],x.first});
      }
    }
  }
  return pair<int,int>(further,tot);
 
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
 
int n,m,q;
cin>>n>>m>>q;
vector<vector<pair<int,int>>> adj(n);
 
for(int i=0;i<m;i++){
  int a,b,l;
  cin>>a>>b>>l;
  adj[a].push_back({b,l});
  adj[b].push_back({a,l});
}
// for (int i = 0; i <= n; i++)
//       vis[i] = 0;
for(int i=0;i<q;i++){
  int a;
  cin>>a;
  if(!vis[a]){
    res[a]=dijkastra(a,n,adj);
    vis[a]=1;
  }
  cout<<res[a].first<<" "<<res[a].second<<endl;
}
 
 return 0;
}