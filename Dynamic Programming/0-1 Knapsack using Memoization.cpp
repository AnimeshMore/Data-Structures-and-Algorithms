#include<bits/stdc++.h>
using namespace std;
int t[100][100];      //Declare according to the constraints


int knapsack(int wt[],int value[],int n,int W){
    if(n==0 || W==0){
        return 0;
    }
    if(t[n][W]!=-1){
        return t[n][W];
    }

    if(wt[n-1]<=W){
        return t[n][W]=max(value[n-1]+knapsack(wt,value,n-1,W-wt[n-1]), knapsack(wt,value,n-1,W));
    }else if(wt[n-1]>W){
        return t[n][W]=knapsack(wt,value,n-1,W);
    }
}

int main(){

  memset(t,-1,sizeof(t));
  int n;
  cin>>n;
  int wt[n],value[n];

  for(int i=0;i<n;i++){
    cin>>wt[i];
  }
  for(int i=0;i<n;i++){
    cin>>value[i];
  }
  int W;
  cin>>W;

  cout<<knapsack(wt,value,n,W)<<"\n";

}
