class Solution {
public:
    int makeit(int ind, string& s, vector<int>& dp){
        if(ind==s.size()){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int a = makeit(ind+1,s,dp);
        int b=0;
        if(ind<s.size()-1){
            if(stoi(s.substr(ind,2))<=26){
                b=makeit(ind+2,s,dp);
            }
        }
        return dp[ind]=a+b;
    }
    int numDecodings(string s) {
        if(s.size()==0) return 0;
        if(s[0]=='0') return 0;
        vector<int> dp(s.size(),-1);
        return makeit(0, s, dp);
    }
};