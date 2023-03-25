#include <iostream>
#include <bits/stdc++.h>
int INF = 1 << 30;
using namespace std;
 
int dist[1000001];
int vis[1000001];
int f,s,g,u,d;
 
void bfs(){
int curr, nextup,nextd;
queue<int> q;
q.push(s);
dist[s]=0;
vis[s]=1;
while(!q.empty()){
  curr=q.front();
  q.pop();
  nextup =curr+u;
  nextd = curr-d;
  if(nextup<=f && !vis[nextup]){
    vis[nextup]=1;
    dist[nextup]=dist[curr]+1;
    q.push(nextup);
  }
  if(nextd>=1 && !vis[nextd]){
    vis[nextd]=1;
    dist[nextd]=dist[curr]+1;
    q.push(nextd);
  }
}
 
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
 
cin>>f>>s>>g>>u>>d;
 
dist[g]=-1;
bfs();
if(dist[g]==-1){
  cout<<"use the stairs"<<endl;
}
else{
  cout<<dist[g]<<endl;
}
 
  return 0;
}