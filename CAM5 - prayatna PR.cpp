#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int dfs(int node,vector<int>adj[],vector<bool>&vis);
 
void solve(int node,vector<int>adj[],vector<bool>&vis){
  if(vis[node])return;
  vis[node]=true;
  for(auto c:adj[node]){
    if(!vis[c]){
      solve(c,adj,vis);
    }
  }
}
 
int dfs(int n,vector<int>adj[],vector<bool>&vis){
  
  int cc=0;
  for(int i=0;i<n;i++){
    if(vis[i]==false){
      cc++;
      solve(i,adj,vis);
    }
  }
  return cc;
}
 
 
int main() {
 
 
    int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int e;
    cin>>e;
    vector<int> adj[n];
    for(int i=0;i<e;i++){
      int a,b;
      cin>>a>>b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    vector<bool>vis(n,false);
    cout<<dfs(n,adj,vis)<<endl; 
}
  return 0;
}
 