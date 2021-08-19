// GFG Problem link - https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1

//Solution
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int checkSum(int arr[],int N,int sum){
    bool t[N+1][sum+1];

  for(int i=0;i<N+1;i++){
    for(int j=0;j<sum+1;j++){
        if(i==0){
            t[i][j]=false;
        }
        if(j==0){
            t[i][j]=true;
        }
    }
  }

   for(int i=1;i<N+1;i++){
    for(int j=1;j<sum+1;j++){
        if(arr[i-1]<=sum){
            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        }else {
            t[i][j] = t[i-1][j];
        }
    }
  }

  return t[N][sum];
}

    bool equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++){
            sum+=arr[i];
        }

        if(sum%2==0){
            return checkSum(arr,N,sum/2);
        }else{
            return false;
        }

    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];

        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
