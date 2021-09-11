//LeetCode Problem Link - https://leetcode.com/problems/scramble-string/

unordered_map<string,bool> mp;

class Solution {
public:
    bool isScramble(string s1, string s2) {

        if(s1.length()!=s2.length()){
            return false;
        }

        int n=s1.length();
        if(n==0){
            return true;
        }

        if(s1==s2){
            return true;
        }

        string key=(s1+" "+s2);
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }

        bool flag=false;

        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i,n-i),s2.substr(i,n-i))){
                flag = true;
                return true;
            }

            if(isScramble(s1.substr(0,i),s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i),s2.substr(0,n-i))){
                flag = true;
                return true;
            }

        }
        mp[key]=flag;
        return false;
    }
};
