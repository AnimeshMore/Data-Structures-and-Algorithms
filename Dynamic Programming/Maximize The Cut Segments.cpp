//GFG Problem Link - https://practice.geeksforgeeks.org/problems/cutted-segments1642/1

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int len[]={x,y,z};

        int t[4][n+1];
          for(int i=0;i<4;i++){
              for(int j=0;j<n+1;j++){
                  if(i==0){
                      t[i][j]=INT_MIN;
                  }else if(j==0){
                      t[i][j]=0;
                  }
                    }
                }


          for(int i=1;i<4;i++){
              for(int j=1;j<n+1;j++){
                   if(len[i-1]<=j){
                       t[i][j]=max(1+t[i][j-len[i-1]],t[i-1][j]);
                    }else if(len[i-1]>j){
                       t[i][j]=t[i-1][j];
                    }
                }
        }
        return t[3][n]<0?0:t[3][n];
    }
};

// { Driver Code Starts.
int main() {

    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
