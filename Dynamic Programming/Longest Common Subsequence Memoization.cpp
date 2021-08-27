#include<bits/stdc++.h>
using namespace std;
int t[100][100];      //Declare according to the constraints


int lcs(string x,string y,int m,int n){
    if(m==0 || n==0){
        return 0;
    }
    if(t[m][n]!=-1){
        return t[m][n];
    }

    if(x[m-1]==y[n-1]){
        return t[m][n]= 1+lcs(x,y,m-1,n-1);
    }else{
        return t[m][n]= max(lcs(x,y,m-1,n),lcs(x,y,m,n-1));
    }
}

int main(){

  memset(t,-1,sizeof(t));
  string x,y;
  cin>>x;
  cin>>y;

  int m=x.size();
  int n=y.size();

  cout<<lcs(x,y,m,n)<<"\n";
  return 0;
}
