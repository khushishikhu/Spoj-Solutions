//Moreover DIJKASTRA'S ALGORITHM

#include <iostream>
#include <bits/stdc++.h>
int INF = 1e9;
int mod = 1e9+7;
using namespace std;
 
 
int spanningtree(int n,vector<vector<int>> graph[],int s,int e){
  int par[n+2];
  int dist[n+2];
  bool mst[n+2];
  for(int i=1;i<=n+1;i++){
    dist[i]=INT_MAX;
    mst[i]=false;
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,s});
  par[s]=-1;
  dist[s]=0;
  while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();
    mst[u]=true;
    for(auto it:graph[u]){
      int v=it[0];
      int w=it[1];
      if(mst[v]==false && dist[u]+w<dist[v]){
        dist[v]=w+dist[u];
        par[v]=u;
        pq.push({dist[v],v});
      }
    }
  }
 
  // int sum=0;
  // for(int i = 2;i<=n+1;i++) {
  //   sum += dist[i];
  // }
 
  return dist[e];
 
}
int main() {
 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
  #endif
 
int t;
cin>>t;
while(t--){
  int n,m,s,e;
  cin>>n>>m>>s>>e;
  vector<vector<int>>graph[n+1];
  for(int i=1;i<=m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    vector<int> t1,t2;
    t1.push_back(b);
    t1.push_back(w);
    graph[a].push_back(t1);
    t2.push_back(a);
    t2.push_back(w);
    graph[b].push_back(t2);
  }
  int ans=spanningtree(n,graph,s,e);
  if(ans==INT_MAX){
    cout<<"NONE"<<endl;
  }
  else{
    cout<<ans<<endl;
  }
 
}
 
 #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
 
return 0;
 
}
