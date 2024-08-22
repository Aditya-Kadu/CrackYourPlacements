class Solution {
public:
    
    int makeit(string& s, string& t, int i1, int i2, vector<vector<int>>& dp){
        if(i2==t.size()){
            return 1;
        }
        if(i1==s.size()){
            return 0;
        }
        if(dp[i1][i2]!=-1) return dp[i1][i2];
        if(s[i1]==t[i2]){
            dp[i1][i2]=makeit(s,t,i1+1,i2+1,dp)+makeit(s,t,i1+1,i2,dp);
        }
        else{
            dp[i1][i2]=makeit(s,t,i1+1,i2,dp);
        }
        return dp[i1][i2];
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
        return makeit(s,t,0,0,dp);
    }
};