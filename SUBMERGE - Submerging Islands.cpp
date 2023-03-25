#include <iostream>
#include <vector>
#include <set>
using namespace std;
 
vector<int> ar[10001];
int in[10001],low[10001],vis[10001];
int timer;
set<int> AP;
 
void dfs(int node,int par){
    vis[node]=1;
    in[node]=low[node]=timer;
    timer++;
    int child_cnt=0;
    
    for(int child:ar[node]){
        if(child==par) continue;
        
        if(vis[child]==1){
            low[node]=min(low[node],in[child]);
        }
        else{
            dfs(child,node);
            child_cnt++;
            low[node]=min(low[node],low[child]);
            if(in[node]<= low[child] && par!= -1){
                AP.insert(node);
            }
        }
    }
    if(par==-1 && child_cnt>1){
        AP.insert(node);
    }
}
 
int main(){
    int n,m,a,b;
 
    while(1){
    cin>>n>>m;
    if(n==0 && m==0){
        break;
    }
    
    for(int i=1;i<=n;i++){
        ar[i].clear();
        vis[i]=0;
    }
        AP.clear();
        timer=1;
        
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            ar[a].push_back(b);
            ar[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(i,-1);
            }
        }
        cout<<AP.size()<<endl;
    
    }
} 