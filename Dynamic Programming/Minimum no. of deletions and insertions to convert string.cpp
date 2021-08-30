//GFG Problem Link - https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int minOperations(string str1, string str2)
	{
	    // Your code goes here
	   int x=str1.size();
	   int y=str2.size();

	   int t[x+1][y+1];

        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }

        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                if(str1[i-1]==str2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
                }
            }
        return (x-t[x][y])+(y-t[x][y]);
	}
};

// { Driver Code Starts.
int main()
{


   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";

    }
    return 0;
}

  // } Driver Code Ends
