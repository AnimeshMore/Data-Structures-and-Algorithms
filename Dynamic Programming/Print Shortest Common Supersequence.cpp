//LeetCode Problem Link - https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        string res;
        int x=a.size();
        int y=b.size();
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
                if(a[i-1]==b[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
                }
        }

        int i=x,j=y;
        while(i>0 && j>0){
            if(a[i-1]==b[j-1]){
                res.push_back(a[i-1]);
                i--;
                j--;
            }else{
                if(t[i][j-1]>t[i-1][j]){
                    res.push_back(b[j-1]);
                    j--;
                }else{
                    res.push_back(a[i-1]);
                    i--;
                }
            }
        }
        while(i>0){
            res.push_back(a[i-1]);
            i--;
        }
        while(j>0){
            res.push_back(b[j-1]);
            j--;
        }



        reverse(res.begin(),res.end());
        return res;
    }
};
