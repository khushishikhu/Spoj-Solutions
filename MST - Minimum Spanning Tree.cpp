//PRIM'S Algorithm


#include <iostream>
#include <bits/stdc++.h>
int INF = 1e9;
int mod = 1e9+7;
using namespace std;
 
int spanningTree(int N, vector<vector<int>> adj[])
    {
        int parent[N+2]; 
          
        int key[N+2]; 
          
        bool mstSet[N+2]; 
      
        for (int i = 1; i <= N+1; i++) 
            key[i] = INT_MAX, mstSet[i] = false; 
        
        priority_queue< pair<int,int>, vector <pair<int,int>> , greater<pair<int,int>> > pq;
    
        key[1] = 0; 
        parent[1] = -1; 
        pq.push({0, 1});
        while(!pq.empty())
        { 
            int u = pq.top().second; 
            pq.pop(); 
            
            mstSet[u] = true; 
            
            for (auto it : adj[u]) {
                int v = it[0];
                int weight = it[1];
                if (mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight; 
                    pq.push({key[v], v});    
                }
            }
                
        }
        int sum = 0;
        for(int i = 2;i<=N+1;i++) {
            if(key[i] != INT_MAX) sum += key[i];
        }
        return sum; 
    }
int main() {
 
  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
  #endif
 
 
int N,m;
cin>>N>>m;
  vector<vector<int>> adj[N+1]; 
  for(int i=1;i<=m;i++){
    int a,b,w;
    cin>>a>>b>>w;
    vector<int> t1,t2;
    t1.push_back(b);
    t1.push_back(w);
    adj[a].push_back(t1);
    t2.push_back(a);
    t2.push_back(w);
    adj[b].push_back(t2);
  }
  
  cout<<spanningTree(N,adj)<<endl;
 
 
 
 #ifdef ONLINEJUDGE
     fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC); // this line gives your code runtime
  #endif
 
return 0;
 
}
 
