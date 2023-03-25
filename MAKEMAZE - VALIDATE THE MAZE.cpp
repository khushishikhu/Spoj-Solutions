#include <iostream>
#include <bits/stdc++.h>
int INF = 1 << 30;
using namespace std;
int n,m;
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
 
char graph[21][21];
int vis[21][21];
int sx,sy,ex,ey;
 
int cnt=0;
int check(){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if((i==0 ||i==n-1 || j==0 || j==m-1) && graph[i][j]=='.'){
        if(cnt==0){
          sx=i;
          sy=j;
        }
        else if(cnt==1){
          ex=i;
          ey=j;
        }
        else return 0;
        cnt++;
      }
    }
  }
  if(cnt==2)return 1;
  else return 0;
}
 
int dfs(int x,int y){
  if(x==ex && y==ey){
    return 1;
  }
  if(vis[x][y]==1){
    return 0;
  }
  vis[x][y]=1;
 
  for(int i=0;i<4;i++){
    int nx=x+dx[i];
    int ny=y+dy[i];
    if(nx>=0 && nx<n && ny>=0 && ny<m && graph[nx][ny]!='#'){
      if(dfs(nx,ny))return 1;
    }
  }
  return 0;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
 
int t;
cin>>t;
while(t--){
    cin>>n>>m;
 
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>graph[i][j];
      }
    }
  if(n==1 && m==1){
    cout<<"invalid"<<endl;
    continue;
  }
  memset(vis,0,sizeof(vis));
  cnt=0;
  if(check()&&dfs(sx,sy)){
    cout<<"valid"<<endl;
  }
  else{
    cout<<"invalid"<<endl;
  }
 
 
}
  return 0;
}
 