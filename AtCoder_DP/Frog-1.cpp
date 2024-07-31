#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
// Topological sort
const int INF = 1e9 + 5;

int solve(int ind,vector<int> &arr){
    int n= arr.size();
    if(ind==n-1){
        return 0;
    }
    if(ind>=n)return 1e4+1;
    
    if (ind+2>=n) {
        return abs(arr[ind] - arr[ind+1])  + solve(ind+1,arr);
    }
    
    return min(abs(arr[ind] - arr[ind+1])  + solve(ind+1,arr), abs(arr[ind] - arr[ind+2]) + solve(ind+2,arr));
    
}

int main() {
	// your code goes here
	int n;
	cin>>n;
	vector<int> arr(n) ;
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
    
    cout<<solve(0,arr)<<endl;
	
	return 0;
	
}
