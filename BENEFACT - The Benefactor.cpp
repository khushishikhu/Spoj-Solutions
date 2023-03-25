#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int maxd,maxnode;
 
void dfs(int node,int dis,vector<vector<pair<int,int>>> &adj,vector<bool>&vis){
  vis[node]=true;
  if(maxd<dis){
    maxd=dis;
    maxnode=node;
  }
  for(auto x:adj[node]){
    if(vis[x.first]==0){
      dfs(x.first,x.second+dis,adj,vis);
    }
  }
  vis[node]=false;
}
 
 
int main() {
 
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<vector<pair<int,int>>> adj(n+1);
    vector<bool>vis(n+1,false);
    for(int i=1;i<n;i++){
      int a,b,c;
      cin>>a>>b>>c;
      adj[a].push_back({b,c});
      adj[b].push_back({a,c});
    }
    maxd=0;
    dfs(1,0,adj,vis);
    maxd=0;
    dfs(maxnode,0,adj,vis);
    cout<<maxd<<endl;
}
  return 0;
}