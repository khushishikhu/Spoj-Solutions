#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int maxnode,maxd;
 
void dfs(int node,int d,vector<int>adj[],vector<bool>&vis){
  
  vis[node]=true;
  if(d>maxd){
    maxd=d;
    maxnode=node;
  }
  for(auto x:adj[node]){
    if(vis[x]==false){
      dfs(x,d+1,adj,vis);
    }
  }
  
}
 
 
int main() {
    int n;
    cin>>n;
    vector<int> adj[10001];
    vector<bool> vis(10001,false);
    for(int i=0;i<n;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    maxd=-1;
    dfs(1,0,adj,vis);
    maxd=-1;
    for(int i=0;i<n;i++)vis[i]=false;
    dfs(maxnode,0,adj,vis);
    cout<<maxd<<endl;
     
 
  return 0;
}
 