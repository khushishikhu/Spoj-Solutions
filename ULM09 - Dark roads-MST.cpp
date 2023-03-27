// Minimum Spanning tree
//PRIM'S ALGORITHM

#include <iostream>
#include <bits/stdc++.h>
int INF = 1e9;
int mod = 1e9+7;
using namespace std;
 
// struct edge{
//   int x;
//   int y;
//   int wt;
// };
 
// class disjointset{
// vector<int>parent,size,rank;
// public:
//   disjointset(int n){
//     parent.resize(n+1);
//     rank.resize(n+1);
//     size.resize(n+1);
//     for(int i=0;i<=n;i++){
//       parent[i]=i;
//       size[i]=1;
//     }
//   }
 
//   int find(int x){
//     if(parent[x]==x)return x;
//     return parent[x]=find(parent[x]);
//   }
 
//   void unionbyrank(int u,int v){
//     int rootx=find(u);
//     int rooty=find(v);
//     if(rootx==rooty)return;
//     if(rank[rootx]<rooty){
//       parent[rootx]=rooty;
//     }
//     else if(rank[rooty]<rootx){
//       parent[rooty]=rootx;
//     }
//     else{
//       parent[rooty]=rootx;
//       rank[rootx]++;
//     }
//   }
 
// };
 
 
// bool comp(edge a, edge b){
//   if(a.wt<b.wt){
//     return true;
//   }
//   return false;
// }
 
int spanningtree(vector<vector<int>> v[],int n){
  int dist[n+1];
  bool mst[n+1];
  for(int i=0;i<n+1;i++){
    dist[i]=INT_MAX;
    mst[i]=false;
  }
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  dist[0]=0;
  pq.push({0,0});
  while(!pq.empty()){
    int u= pq.top().second;
    pq.pop();
    mst[u]=true;
    for(auto it:v[u]){
      int x=it[0];
      int wt=it[1];
      if(mst[x]==false && wt<dist[x]){
        dist[x]=wt;
        pq.push({dist[x],x});
      }
    }
  }
  int sum=0;
  for(int i=1;i<n;i++){
    if(dist[i]!=INT_MAX)sum+=dist[i];
 
  }
 
  return sum;
 
}
 
int main() {
 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
  #endif
 
while(1){
  int n,m;
  cin>>n>>m;
  if(n==0 && m==0){
    break;
  }
  vector<vector<int>> v[n+1];
 
  int tot=0;
  for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    vector<int>t1,t2;
    t1.push_back(b);
    t1.push_back(w);
    v[a].push_back(t1);
    t2.push_back(a);
    t2.push_back(w);
    v[b].push_back(t2);
    tot+=w;
  }
  int sum=spanningtree(v,n);
//   for(int i=0;i<n;i++){
//     par[i]=-1;
//   }
// int sum=0;
//   sort(v.begin(),v.end(),comp);
//   for(int i=0;i<m;i++){
//     int rx=ds.find(v[i].x);
//     int ry=ds.find(v[i].y);
//     if(rx!=ry){
//       sum+=v[i].wt;
//       ds.unionbyrank(rx,ry);
//     }
//   }
 
  cout<<tot-sum<<endl;
 
}
 
 
 
 #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
 
return 0;
 
}
 
 