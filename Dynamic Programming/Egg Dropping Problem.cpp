// GFG Problem Link -https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    int t[201][201];
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.
    int solve(int n,int k){
        if(k==0 ||k==1){
            return k;
        }

        if(n==1){
            return k;
        }

        if(t[n][k]!=-1){
            return t[n][k];
        }

        int mn = INT_MAX;

        for(int i=1;i<=k;i++){
            int top,bottom;
            if(t[n-1][k-1]!=-1){
                 bottom = t[n-1][i-1];
            }else{
                 bottom = solve(n-1,i-1);
            }

            if(t[n][k-i]!=-1){
                top = t[n][k-i];
            }else{
                 top = solve(n,k-i);
            }

            int temp = 1 + max(top,bottom);

            mn = min(temp,mn);

        }
        return t[n][k]=mn;
    }


    int eggDrop(int n, int k)
    {
        // your code here
        memset(t,-1,sizeof(t));
        return solve(n,k);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
