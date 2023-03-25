#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int maxsum(int arr1[], int arr2[], int n1, int n2){
    int i=0;
    int j=0;
    int max_sum=0;
    int sum1 =0;
    int sum2 =0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            sum1 += arr1[i];
            i++;
        }
        else if(arr1[i]>arr2[j]){
            sum2 += arr2[j];
            j++;
        }
        else{
            max_sum = max(sum1,sum2) + max_sum;
            max_sum = max_sum + arr1[i];
            sum1=0;
            sum2=0;
            i++;
            j++;
        }
    }
 
    while(i<n1){
        sum1 = sum1 + arr1[i];
        i++;
    }
    while(j<n2){
        sum2 = sum2 + arr2[j];
        j++;
    }
    max_sum = max_sum + max(sum1,sum2);
    return max_sum;
 
}
 
int main(){
  
    while(1){
        int n1,n2,i;
        cin>>n1;
        if(!n1){
            break;
        }
        int arr1[n1];
        for(i=0;i<n1;++i){
            cin>>arr1[i];
        }
        cin>>n2;
        int arr2[n2];
        for(i=0;i<n2;++i){
            cin>>arr2[i];
        }
        cout<<maxsum(arr1,arr2,n1,n2)<<endl;
    }
 
    return 0;
}
 