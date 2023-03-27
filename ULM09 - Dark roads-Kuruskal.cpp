//Kuruskal Algorithm

#include <iostream>
#include <bits/stdc++.h>
int INF = 1e9;
int mod = 1e9+7;
using namespace std;
 
struct edge{
  int x;
  int y;
  int wt;
};
 
class disjointset{
vector<int>parent,size,rank;
public:
  disjointset(int n){
    parent.resize(n+1);
    rank.resize(n+1);
    size.resize(n+1);
    for(int i=0;i<=n;i++){
      parent[i]=i;
      size[i]=1;
    }
  }
 
  int find(int x){
    if(parent[x]==x)return x;
    return parent[x]=find(parent[x]);
  }
 
  void unionbyrank(int u,int v){
    int rootx=find(u);
    int rooty=find(v);
    if(rootx==rooty)return;
    if(rank[rootx]<rooty){
      parent[rootx]=rooty;
    }
    else if(rank[rooty]<rootx){
      parent[rooty]=rootx;
    }
    else{
      parent[rooty]=rootx;
      rank[rootx]++;
    }
  }
 
};
 
 
bool comp(edge a, edge b){
  if(a.wt<b.wt){
    return true;
  }
  return false;
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
  disjointset ds(n);
  vector<edge>v;
  int par[n];
  edge tmp;
  int tot=0;
  for(int i=0;i<m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    tmp.x=b;
    tmp.y=a;
    tmp.wt=w;
    tot+=w;
    v.push_back(tmp);
  }
  for(int i=0;i<n;i++){
    par[i]=-1;
  }
int sum=0;
  sort(v.begin(),v.end(),comp);
  for(int i=0;i<m;i++){
    int rx=ds.find(v[i].x);
    int ry=ds.find(v[i].y);
    if(rx!=ry){
      sum+=v[i].wt;
      ds.unionbyrank(rx,ry);
    }
  }
 
  cout<<tot-sum<<endl;
 
}
 
 
 
 #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
 
return 0;
 
}