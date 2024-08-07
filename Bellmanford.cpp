
#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
#define ll long long
using namespace std;
// Bell -man Ford algo to detect the negative weight edge cycle

int INF = 1e9;

vector<int> bellman(int n,vector<vector<int>> &edges,int source){
    vector<int> dist(n,INF);
    dist[source]=0;
    for(int i=0;i<n-1;i++){
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if(dist[u]!=INF && dist[u]+wt < dist[v]){
                dist[v] = dist[u]+wt;
            }
        }
    }
    
}

int main() {
	// your code goes here
	
	
	return 0;
}
