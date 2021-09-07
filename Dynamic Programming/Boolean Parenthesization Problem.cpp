// GFG Problem Link - https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
int t[201][201][2];


class Solution{
public:

   int solve(string S, int i,int j, int isTrue){
       if(i>j){
           return false;
       }
       if(i==j){
           if(isTrue==1){
               return S[i]=='T';
           }else{
               return S[i]=='F';
           }
       }

       if(t[i][j][isTrue]!=-1){
           return t[i][j][isTrue];
       }

       int ans=0;

       for(int k=i+1;k<=j-1;k=k+2){

           int lf,lt,rf,rt;

           if(t[i][k-1][0]==-1){
               lf = solve(S,i,k-1,0);
           }else{
               lf = t[i][k-1][0];
           }

           if(t[i][k-1][1]==-1){
               lt = solve(S,i,k-1,1);
           }else{
               lt = t[i][k-1][1];
           }

           if(t[k+1][j][0]==-1){
               rf = solve(S,k+1,j,0);
           }else{
               rf = t[k+1][j][0];
           }

           if(t[k+1][j][1]==-1){
               rt = solve(S,k+1,j,1);
           }else{
               rt = t[k+1][j][1];
           }

           if(S[k]=='&'){
               if(isTrue==1){
                   ans= ans + lt*rt;
               }else{
                   ans=ans + lf*rf + lf*rt+ lt*rf;
               }
           }else if(S[k]=='|'){
               if(isTrue==1){
                   ans = ans + lt*rt + lf*rt+ lt*rf;
               }else{
                   ans = ans + lf*rf;
               }
           }else if(S[k]=='^'){
               if(isTrue==1){
                   ans = ans +lf*rt+ lt*rf;
               }else{
                   ans = ans + lf*rf+lt*rt;
               }
           }
           t[i][j][isTrue] = ans%1003;
       }
       return ans%1003;
   }


    int countWays(int N, string S){
        // code here
        memset(t,-1,sizeof(t));
        return solve(S,0,N-1,1);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;

        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
