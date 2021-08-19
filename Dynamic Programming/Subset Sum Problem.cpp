//GFG Problem Link - https://www.geeksforgeeks.org/subset-sum-problem-dp-25/

//Solution
#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  int s;  // Required Sum
  cin>>s;

  bool t[n+1][s+1];

  //Initialization
  for(int i=0;i<n+1;i++){
    for(int j=0;j<s+1;j++){
        if(i==0){
            t[i][j]=false;
        }
        if(j==0){
            t[i][j]=true;
        }
    }
  }

   for(int i=1;i<n+1;i++){
    for(int j=1;j<s+1;j++){
        if(arr[i-1]<=s){
            t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
        }else {
            t[i][j] = t[i-1][j];
        }
    }
  }

  cout<<t[n][s]<<endl;
  return 0;
}
