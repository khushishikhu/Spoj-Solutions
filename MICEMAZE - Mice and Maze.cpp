#include <iostream>
#include <bits/stdc++.h>
const int INF = 1e9;
using namespace std;
#define ll long long 
#define MAX 105
 
vector<vector<pair<int,int>>> v;
vector<int> dist(MAX,INF);
 
 
void dijkastra(int s){
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  pq.push({0,s});
  dist[s]=0;
  while(!pq.empty()){
    int dis=pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for(auto x:v[node]){
      int u=x.first;
      int w=x.second;
      if(w+dis < dist[u]){
        dist[u]=w+dis;
        pq.push({dist[u],u});
      }
    }
  }
 
}
 
int main() {
 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
  #endif
 
  int n;
  cin>>n;
  int e;
  cin>>e;
  int t;
  cin>>t;
  int m;
  cin>>m;
  v= vector<vector<pair<int,int>>>(MAX+5,vector<pair<int,int>>());
  dist= vector<int> (MAX,INF);
  for(int i=0;i<m;i++){
    int x,y,wt;
    cin>>x>>y>>wt;
    v[y].push_back({x,wt});
  }
int cnt=0;
  dijkastra(e);
  
  for(auto i=1;i<=n;i++){
    if(dist[i]<=t){
      cnt++;
    }
  }
  
  cout<<cnt<<endl;
 
  cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
return 0;
 
}
 
